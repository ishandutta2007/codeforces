#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

const int MAXN = (int) 1e5;

struct Edge {
    int x, y, z;
}edges[MAXN + 1];

vector < pair <int, int> > g[MAXN + 1];
vector <int> sol, ord;
bool vis[MAXN + 1];
int pos[MAXN + 1];
int n, m;

void dfs(int nod, int val) {
    vis[nod] = 1;
    for(auto it : g[nod]) {
        if(vis[it.first] == 0 && it.second > val) {
            dfs(it.first, val);
        }
    }
    ord.push_back(nod);
    pos[nod] = ord.size();
}

vector <int> new_g[MAXN + 1];
char seen[MAXN + 1];

void dfs1(int nod, bool &ans) {
    seen[nod] = 1;
    for(auto it : new_g[nod]) {
        if(seen[it] == 0) {
            dfs1(it, ans);
        }
        else if(seen[it] == 1) {
            ans = 1;
        }
    }
    seen[nod] = 2;
}

inline bool cycle() {
    memset(seen, 0, sizeof(seen));
    for(int i = 1; i <= n; i++) {
        if(seen[i] == 0) {
            bool cur = 0;
            dfs1(i, cur);
            if(cur == 1) {
                return 1;
            }
        }
    }
    return 0;
}

inline bool check(int val) {
    memset(vis, 0, sizeof(vis));
    ord.clear();
    int i;
    for(i = 1; i <= n; i++) {
        if(vis[i] == 0) {
            dfs(i, val);
        }
        new_g[i].clear();
    }
    sol.clear();
    for(i = 1; i <= m; i++) {
        if(edges[i].z > val) {
            new_g[edges[i].x].push_back(edges[i].y);
        }
        else {
            if(pos[edges[i].x] < pos[edges[i].y]) {
                sol.push_back(i);
                new_g[edges[i].y].push_back(edges[i].x);
            }
            else {
                new_g[edges[i].x].push_back(edges[i].y);
            }
        }
    }
    if(cycle()) {
        return 0;
    }
    return 1;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(i = 1; i <= m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        edges[i] = {x, y, z};
        g[x].push_back({y, z});
    }
    int res = -1;
    for(int step = 1 << 30; step; step >>= 1) {
        if(check(res + step) == 0) {
            res += step;
        }
    }
    check(res + 1);
    cout << res + 1 << " " << sol.size() << "\n";
    for(auto it : sol) {
        cout << it << " ";
    }
    //cin.close();
    //cout.close();
    return 0;
}