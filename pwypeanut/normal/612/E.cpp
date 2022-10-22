#include <bits/stdc++.h>
using namespace std;

int N, arr[1000005], ans[1000005], cur;
bool vis[1000005];
vector<int> V[1000005];
pair<int, int> P[1000005];

void dfs(int x) {
    if (vis[x]) return;
    else vis[x] = 1;
    V[cur].push_back(x);
    dfs(arr[x - 1]);
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
    for (int i = 1; i <= N; i++) {
        if (vis[i]) continue;
        dfs(i);
        cur++;
    }
    for (int i = 0; i < cur; i++) P[i] = make_pair(V[i].size(), i);
    sort(P, P + cur);
    for (int i = 0; i < cur; i++) {
        if (P[i].first % 2 == 1) {
            // odd cycle, so can be independent
            for (int j = 0; j < V[P[i].second].size(); j++) {
                ans[V[P[i].second][j] - 1] = V[P[i].second][((j + V[P[i].second].size() / 2 + 1) + V[P[i].second].size()) % V[P[i].second].size()];
            }
        } else {
            // even cycle, therefore need next
            if (i + 1 == cur) {
                printf("-1\n");
                exit(0);
            }
            if (V[P[i].second].size() != V[P[i + 1].second].size()) {
                printf("-1\n");
                exit(0);
            }
            for (int j = 0; j < V[P[i].second].size(); j++) {
                ans[V[P[i].second][j] - 1] = V[P[i + 1].second][j];
                ans[V[P[i + 1].second][j] - 1] = V[P[i].second][(j + 1) % V[P[i].second].size()];
            }
            i++;
        }
    }
    for (int i = 0; i < N; i++) printf("%d ", ans[i]);
    printf("\n");
}