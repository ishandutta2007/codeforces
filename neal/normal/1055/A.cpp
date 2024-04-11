#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N, S;
vector<int> A, B;
vector<bool> visited;

void dfs(int station) {
    if (visited[station])
        return;

    visited[station] = true;

    if (A[station]) {
        for (int i = station + 1; i <= N; i++)
            if (A[i])
                dfs(i);
    }

    if (B[station]) {
        for (int i = station - 1; i >= 1; i--)
            if (B[i])
                dfs(i);
    }
}

int main() {
    scanf("%d %d", &N, &S);
    A.assign(N + 2, 0);
    B.assign(N + 2, 0);

    for (int i = 1; i <= N; i++)
        scanf("%d", &A[i]);

    for (int i = 1; i <= N; i++)
        scanf("%d", &B[i]);

    visited.assign(N + 2, false);
    dfs(1);
    puts(visited[S] ? "YES" : "NO");
}