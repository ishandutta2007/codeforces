#include <bits/stdc++.h>
using namespace std;

bool fail;
int N, M, color[100005];
vector< pair<int, int> > V[100005];

void dfs(int x, int col) {
    color[x] = col;
    for (int i = 0; i < V[x].size(); i++) {
        int target = V[x][i].first;
        if (color[target] == -1) dfs(target, col ^ V[x][i].second);
        else if (color[target] != col ^ V[x][i].second) fail = 1;
    }
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        V[a-1].push_back(make_pair(b-1, !c));
        V[b-1].push_back(make_pair(a-1, !c));
    }
    memset(color, -1, sizeof(color));
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (color[i] == -1) {
            dfs(i, 0);
            cnt++;
        }
    }
    if (fail) printf("0\n");
    else {
        int ans = 1;
        for (int i = 0; i < cnt - 1; i++) {
            ans *= 2;
            ans %= 1000000007;
        }
        printf("%d\n", ans);
    }
}