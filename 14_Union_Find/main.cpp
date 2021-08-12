//
//  main.cpp
//  14_Union_Find
//
//  Created by 세광 on 2021/08/12.
//

#include <iostream>

using namespace std;

int GetParent(int parent[], int x) {
    if (parent[x] == x) return x;
    return parent[x] = GetParent(parent, parent[x]);
}

// 각 부모 노드 합치기
void UnionParent(int parent[], int a, int b) {
    a = GetParent(parent, a);
    b = GetParent(parent, b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

// 같은 부모 노드를 가지는지 확인
int FindParent(int parent[], int a, int b) {
    a = GetParent(parent, a);
    b = GetParent(parent, b);
    if (a == b) return 1;
    else return 0;
}

int main() {
    int parent[11];
    for (int i = 1; i <= 10; i++) {
        parent[i] = i;
    }
    
    for (int i = 1; i <= 3; i++) {
        UnionParent(parent, i, i + 1);
    }
    for (int i = 5; i <= 7; i++) {
        UnionParent(parent, i, i + 1);
    }
    
    cout << "1과 5는 연결되어 있나요? " << FindParent(parent, 1, 5) << endl;
    UnionParent(parent, 1, 5);
    cout << "1과 5는 연결되어 있나요? " << FindParent(parent, 1, 5) << endl;
}
