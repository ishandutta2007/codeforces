#include <bits/stdc++.h>
using namespace std;

int N, K, twok[100005][18], d_costup[100005], d_costdown[100005], ndepth[100005], delta[100005][2], mods[1000005];
set< pair<int, int> > cost_edges;
vector<int> V[100005];
long long ans = 0;

pair<int, int> dfs2(int node, int par) {
    int up = delta[node][0], down = delta[node][1];
    for (int i = 0; i < V[node].size(); i++) {
        if (V[node][i] == par) continue;
        pair<int, int> P = dfs2(V[node][i], node);
        up += P.first;
        down += P.second;
    }
    if (cost_edges.find(make_pair(par, node)) != cost_edges.end()) {
        ans += (long long)mods[down] + 1000000006;
        //printf("%d %d = %d\n", par, node, ans);
        ans %= 1000000007;
    }
    if (cost_edges.find(make_pair(node, par)) != cost_edges.end()) {
        ans += (long long)mods[up] + 1000000006;
        //printf("%d %d = %d\n", node, par, ans);
        ans %= 1000000007;
    }
    return make_pair(up, down);
}

void dfs(int node, int par, int costup, int costdown, int depth) {
//printf("twok of %d\n", node);
    twok[node][0] = par;
    //printf("%d\n", par);
    d_costup[node] = costup;
    d_costdown[node] = costdown;
    ndepth[node] = depth;
    for (int i = 1; i < 18; i++) {
        if (twok[node][i-1] == -1) break;
        else twok[node][i] = twok[twok[node][i-1]][i-1];
        //printf("%d\n", twok[node][i]);
    }
    //printf(" 1 = %d\n", twok[node][1]);
    for (int i = 0; i < V[node].size(); i++) {
        if (V[node][i] == par) continue;
        else if (cost_edges.find(make_pair(node, V[node][i])) != cost_edges.end()) dfs(V[node][i], node, costup, costdown + 1, depth + 1);
        else if (cost_edges.find(make_pair(V[node][i], node)) != cost_edges.end()) dfs(V[node][i], node, costup + 1, costdown, depth + 1);
        else dfs(V[node][i], node, costup, costdown, depth + 1);
    }
}

int lca(int x, int y) {
    if (x == y) return x;
    if (ndepth[x] > ndepth[y]) {
        int diffdepth = ndepth[x] - ndepth[y];
        for (int i = 0; i < 18; i++) if (diffdepth & (1 << i)) x = twok[x][i];
    }
    if (ndepth[y] > ndepth[x]) {
        int diffdepth = ndepth[y] - ndepth[x];
        for (int i = 0; i < 18; i++) if (diffdepth & (1 << i)) y = twok[y][i];
    }
    if (x == y) return x;
    for (int i = 17; i >= 0; i--) {
        if (twok[x][i] == twok[y][i]) continue;
        else {
            x = twok[x][i];
            y = twok[y][i];
        }
    }
    return twok[x][0];
}

int main() {
    long long ori = 1;
    for (int i = 0; i <= 1000003; i++) {
        mods[i] = ori;
        ori *= 2;
        ori %= 1000000007;
        if (ori == 0) break;
    }
    scanf("%d", &N);
    for (int i = 0; i < N-1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        V[a].push_back(b);
        V[b].push_back(a);
        int op;
        scanf("%d", &op);
        if (op == 0) continue;
        else cost_edges.insert(make_pair(b, a));
    }
    memset(twok, -1, sizeof(twok));
    dfs(0, -1, 0, 0, 0);
    int prev = 0;
    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        int x;
        scanf("%d", &x);
        x--;
        int node = lca(x, prev);
        //printf("%d to %d, lca %d\n", prev, x, node);
        delta[node][0]--;
        delta[prev][0]++;
        delta[node][1]--;
        delta[x][1]++;
        prev = x;
    }
    dfs2(0, -1);
    printf("%I64d\n", ans);
}