#include <bits/stdc++.h>
using namespace std;

int N, M, cur, color[1000005], ans[1000005];
vector< pair<int, int> > adjlist[1000005];
vector<int> adjlist2[1000005], back[1000005];
vector< vector<int> > V;
vector< pair<int, int> > tmp;
vector<int> topo;
bool vis[1000005];

void dfs(int x) {
    if (vis[x]) return;
    else vis[x] = 1;
    color[x] = cur;
    for (int i = 0; i < adjlist[x].size(); i++) if (adjlist[x][i].second == 0) dfs(adjlist[x][i].first);
}

void dfs2(int x) {
    if (vis[x]) return;
    else vis[x] = 1;
    for (int i = 0; i < adjlist2[x].size(); i++) dfs2(adjlist2[x][i]);
    topo.push_back(x);
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) {
        vector<int> v;
        for (int j = 0; j < M; j++) {
            int x;
            scanf("%d", &x);
            v.push_back(x);
        }
        V.push_back(v);
    }
    for (int i = 0; i < N; i++) {
        tmp.clear();
        for (int j = 0; j < M; j++) tmp.push_back(make_pair(V[i][j], j));
        sort(tmp.begin(), tmp.end());
        for (int j = 0; j < M - 1; j++) {
            if (tmp[j].first == tmp[j + 1].first) {
                // equal
                adjlist[i * M + tmp[j].second].push_back(make_pair(i * M + tmp[j + 1].second, 0));
                adjlist[i * M + tmp[j + 1].second].push_back(make_pair(i * M + tmp[j].second, 0));
            } else {
                // not equal
                adjlist[i * M + tmp[j].second].push_back(make_pair(i * M + tmp[j + 1].second, 1));
            }
        }
    }
    for (int j = 0; j < M; j++) {
        tmp.clear();
        for (int i = 0; i < N; i++) tmp.push_back(make_pair(V[i][j], i));
        sort(tmp.begin(), tmp.end());
        for (int i = 0; i < N - 1; i++) {
            if (tmp[i].first == tmp[i + 1].first) {
                // equal
                adjlist[tmp[i].second * M + j].push_back(make_pair(tmp[i + 1].second * M + j, 0));
                adjlist[tmp[i + 1].second * M + j].push_back(make_pair(tmp[i].second * M + j, 0));
            } else {
                // not equal
                adjlist[tmp[i].second * M + j].push_back(make_pair(tmp[i + 1].second * M + j, 1));
            }
        }
    }
    for (int i = 0; i < N * M; i++) {
        if (!vis[i]) {
            dfs(i);
            cur++;
        }
    }
    for (int i = 0; i < N * M; i++) {
        for (int j = 0; j < adjlist[i].size(); j++) {
            if (adjlist[i][j].second == 1) {
                adjlist2[color[i]].push_back(color[adjlist[i][j].first]);
                back[color[adjlist[i][j].first]].push_back(color[i]);
            }
        }
    }
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < cur; i++) if (!vis[i]) dfs2(i);
    reverse(topo.begin(), topo.end());
    for (int i = 0; i < topo.size(); i++) {
        int node = topo[i];
        ans[node] = 1;
        for (int j = 0; j < back[node].size(); j++) ans[node] = max(ans[node], ans[back[node][j]] + 1);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (j) printf(" ");
            printf("%d", ans[color[i * M + j]]);
        }
        printf("\n");
    }
}