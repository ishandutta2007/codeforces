#include <bits/stdc++.h>
using namespace std;

int N, K, pre[300005], re[300005], twok[300005][20], d[300005], cur, nodecount;
vector<int> V[300005];
set<int> S;

void dfs(int x, int par, int di) {
    pre[x] = cur++;
    re[cur-1] = x;
    d[x] = di;
    twok[x][0] = par;
    for (int i = 1; i < 20; i++) {
        if (twok[x][i-1] == -1) break;
        twok[x][i] = twok[twok[x][i-1]][i-1];
    }
    for (int i = 0; i < V[x].size(); i++) if (V[x][i] != par) dfs(V[x][i], x, di + 1);
}

int lca(int x, int y) {
    if (d[x] > d[y]) {
        int diff = d[x] - d[y];
        for (int i = 0; i < 20; i++) if (diff & (1 << i)) x = twok[x][i];
    }
    if (d[y] > d[x]) {
        int diff = d[y] - d[x];
        for (int i = 0; i < 20; i++) if (diff & (1 << i)) y = twok[y][i];
    }
    if (x == y) return x;
    for (int i = 19; i >= 0; i--) {
        if (twok[x][i] != twok[y][i]) {
            x = twok[x][i];
            y = twok[y][i];
        }
    }
    return twok[x][0];
}

int dist(int x, int y) {
    return d[x] + d[y] - 2 * d[lca(x, y)];
}

int main() {
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
    scanf("%d%d", &a, &b);
        a--;
        b--;
        V[a].push_back(b);
        V[b].push_back(a);
    }
    memset(twok, -1, sizeof(twok));
    dfs(0, -1, 0);
    int end = 0, ans = 0;
    for (int start = 0; start < N; start++) {
        while (nodecount <= K) {
            if (end == N) {
                ans = max(ans, end - start);
                break;
            }
            ans = max(ans, end - start);
           // printf("%d %d: %d\n", start, end, nodecount);
            // inserting end
            S.insert(pre[end]);
            if (S.size() == 1) nodecount++;
            else if (S.size() == 2) nodecount += dist(re[*S.begin()], re[*S.rbegin()]);
            else if (*S.begin() == pre[end]) {
                nodecount += (dist(end, re[*(++S.begin())]) + dist(end, re[*(--S.end())]) - dist(re[*(++S.begin())], re[*S.rbegin()])) / 2;
            }
            else if (*S.rbegin() == pre[end]) nodecount += (dist(end, re[*(S.begin())]) + dist(end, re[*(--(--S.end()))]) - dist(re[*(S.begin())], re[*(--(--S.end()))])) / 2;
            else {
                set<int>::iterator it = S.find(pre[end]);
                int l = *(--it);
                ++it;
                int r = *(++it);
                nodecount += (dist(end, re[l]) + dist(end, re[r]) - dist(re[l], re[r])) / 2;
            }
            end++;
        }
        //printf("%d %d: %d\n", start, end, nodecount);
        if (S.size() == 1) nodecount--;
        else if (S.size() == 2) nodecount = 1;
        else if (*S.begin() == pre[start]) nodecount -= (dist(start, re[*(++S.begin())]) + dist(start, re[*(--S.end())]) - dist(re[*(++S.begin())], re[*S.rbegin()])) / 2;
        else if (*S.rbegin() == pre[start]) nodecount -= (dist(start, re[*(S.begin())]) + dist(start, re[*(--(--S.end()))]) - dist(re[*(S.begin())], re[*(--(--S.end()))])) / 2;
        else {
            set<int>::iterator it = S.find(pre[start]);
            int l = *(--it);
            ++it;
            int r = *(++it);
            nodecount -= (dist(start, re[l]) + dist(start, re[r]) - dist(re[l], re[r])) / 2;
        }
        S.erase(pre[start]);
    }
    printf("%d\n", ans);
}