#include <bits/stdc++.h>
using namespace std;

vector<int> v, v1, ans;
vector<int> nodes;
int N, M, d[100005], r[100005], bt[100005], d2[100005];
bool vis[100005];
vector< pair<int, int> > V[100005], dag[100005];
queue< pair<int, int> > Q;
queue<int> Q2;
vector<int> starts;
vector<int> layers[100005];

void dfs_precomp(int node) {
    if (vis[node]) return;
    else vis[node] = 1;
    for (int i = 0; i < V[node].size(); i++) {
        if (V[node][i].second != 0) continue;
        else dfs_precomp(V[node][i].first);
    }
    return;
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void dfs5(int node, int source, int target) {
    if(node != target) ans.push_back(node);
    if (node == source) return;
    dfs5(bt[node], source, target);
}

void dfs4(int node, int target) {
    //printf("%d %d\n", node, target);
    Q2.push(node);
    vis[node] = 1;
    while (!Q2.empty()) {
        int n = Q2.front();
        Q2.pop();
        if (n == target) {
            dfs5(target, node, target);
            return;
        }
        for (int i = 0; i < V[n].size(); i++) {
            if (V[n][i].second != 0) continue;
            if (vis[V[n][i].first]) continue;
            bt[V[n][i].first] = n;
            vis[V[n][i].first] = 1;
            Q2.push(V[n][i].first);
        }
    }
}

void dfs3(int node) {
    nodes.push_back(node);
    int lr = 2000000000, lidx = 0;
    for (int i = 0; i < dag[node].size(); i++) {
        int othernode = dag[node][i].first;
        int rerank = dag[node][i].second * 1000000 + r[othernode];
        if (rerank < lr && r[othernode] != -1) {
            lr = rerank;
            lidx = i;
        }
    }
    if (node == 0) {
        for (int i = 0; i < v.size(); i++) printf("%d", v[i]);
        if (v.size() == 0) printf("0");
        printf("\n");
        for (int i = nodes.size() - 1; i >= 0; i--) ans.push_back(nodes[i]);
        memset(vis, 0, sizeof(vis));
        dfs4(N-1, nodes[0]);
        printf("%d\n", ans.size());
        for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
        printf("\n");
        exit(0);
    }
    v.push_back(dag[node][lidx].second);
    dfs3(dag[node][lidx].first);
    v.pop_back();
    nodes.pop_back();
}

int main() {
//freopen("g.txt", "r", stdin);
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        V[a].push_back(make_pair(b, c));
        V[b].push_back(make_pair(a, c));
    }
    dfs_precomp(N-1);
    for (int i = 0; i < N; i++) if (vis[i]) Q.push(make_pair(0, i));
    for (int i = 0; i < N; i++) if (vis[i]) starts.push_back(i);
    //for (int i = 0; i < N; i++) if (vis[i]) printf("%d\n", i);
    memset(d, -1, sizeof(d));
    memset(d2, -1, sizeof(d2));
    for (int i = 0; i < N; i++) if (vis[i]) d[i] = 0;
    while (!Q.empty()) {
        int n = Q.front().second;
        int dist = Q.front().first;
        Q.pop();
        for (int i = 0; i < V[n].size(); i++) {
            int newnode = V[n][i].first, newd = dist + 1;
            if (d[newnode] == -1 || d[newnode] == newd) {
                dag[n].push_back(make_pair(newnode, V[n][i].second));
                //printf("%d %d = %d\n", n, newnode, V[n][i].second);
            }
            if (d[newnode] == -1) {
                d[newnode] = newd;
                Q.push(make_pair(newd, newnode));
            }
        }
    }
    while (!Q.empty()) Q.pop();
    Q.push(make_pair(0, N-1));
    while (!Q.empty()) {
        int n = Q.front().second;
        int dist = Q.front().first;
        Q.pop();
        d2[n] = dist;
        for (int i = 0; i < V[n].size(); i++) {
            int newnode = V[n][i].first, newd = dist + 1;
            if (d2[newnode] == -1) {
                d2[newnode] = newd;
                Q.push(make_pair(newd, newnode));
            }
        }
    }
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < starts.size(); i++) dag[N].push_back(make_pair(starts[i], 0));
    for (int i = 0; i < N; i++) d[i]++;
    for (int i = 0; i <= N; i++) layers[d[i]].push_back(i);
    memset(r, -1, sizeof(r));
    r[0] = 0;
    for (int i = d[0] - 1; i >= 0; i--) {
        //printf("computing ranks for distance %d\n", i);
        vector<int> ranks;
        for (int j = 0; j < layers[i].size(); j++) {
            int node = layers[i][j];
            //printf("%d\n", node);
            int mini = 2000000000;
            for (int k = 0; k < dag[node].size(); k++) {
                int nextnode = dag[node][k].first;
                if (r[nextnode] == -1) continue;
                int rank = dag[node][k].second * 1000000 + r[nextnode];
                mini = min(mini, rank);
            }
            if (mini == 2000000000) r[node] = -1;
            else {
                r[node] = mini;
                //printf("premature rank is %d\n", mini);
                ranks.push_back(mini);
            }
        }
        sort(ranks.begin(), ranks.end());
        ranks.resize(unique(ranks.begin(), ranks.end()) - ranks.begin());
        for (int j = 0; j < layers[i].size(); j++) if (r[layers[i][j]] != -1) r[layers[i][j]] = lower_bound(ranks.begin(), ranks.end(), r[layers[i][j]]) - ranks.begin();
    }
    pair<int, int> best = make_pair(2000000000, 2000000000);
    int node1 = 0;
    for (int i = 0; i < starts.size(); i++) {
        if (r[starts[i]] == -1) continue;
        pair<int, int> mine = make_pair(r[starts[i]], d2[starts[i]]);
        if (mine < best) {
            best = mine;
            node1 = starts[i];
        }
    }
    dfs3(node1);
    assert(false);
}