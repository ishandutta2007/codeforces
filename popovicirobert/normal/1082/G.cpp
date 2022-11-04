#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const ll INF = 1e16;
const int MAXN = 1000;
const int D = 2004;
const int S = 2005;

vector <int> g[S + 1];
ll cap[S + 1][S + 1];

inline void addEdge(int x, int y, ll c) {
    g[x].push_back(y);
    cap[x][y] += c;
    g[y].push_back(x);
}

int from[S + 1];
int vis[S + 1], now;

inline bool bfs() {
    queue <int> Q;
    now++;
    Q.push(S);
    vis[S] = now;
    while(!Q.empty()) {
        int nod = Q.front();
        Q.pop();
        for(auto it : g[nod]) {
            if(vis[it] != now && cap[nod][it] > 0) {
                from[it] = nod;
                Q.push(it);
                vis[it] = now;
            }
        }
    }
    return vis[D] == now;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m, x, y, c;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(i = 1; i <= n; i++) {
        cin >> c;
        addEdge(S, i, c);
    }
    ll ans = 0;
    for(i = 1; i <= m; i++) {
        cin >> x >> y >> c;
        addEdge(x, i + n, INF);
        addEdge(y, i + n, INF);
        addEdge(i + n, D, c);
        ans += c;
    }
    while(bfs()) {
        ll mn = INF;
        int nod = D;
        while(nod != S) {
            mn = min(mn, cap[from[nod]][nod]);
            nod = from[nod];
        }
        ans -= mn;
        nod = D;
        while(nod != S) {
            cap[from[nod]][nod] -= mn;
            cap[nod][from[nod]] += mn;
            nod = from[nod];
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}