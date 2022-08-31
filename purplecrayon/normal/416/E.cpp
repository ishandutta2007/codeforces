#include "bits/stdc++.h"
using namespace std;

template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 5e2+10, MAXM = 4e4+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 110, INF = 1e9+10, MAXA = 62, MAXB = 24, MAXBB = (1<<MAXB), MOD2=MOD-1;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};


int n, m;
int d[MAXN][MAXN], ans[MAXN], push[MAXN];
vector<ar<int, 2>> in[MAXN];
vector<int> adj[MAXN];
bitset<MAXN> vis[MAXN];
bool hit[MAXN];

void rec(int c) {
    if (hit[c]) return;
    hit[c] = 1, vis[c][c] = 1;
    for (auto nxt : adj[c]) {
        rec(nxt);
        vis[c] |= vis[nxt];
    }
}
void get(int st) {
    for (int i = 0; i < n; i++) adj[i].clear();

    for (int i = 0; i < n; i++) {
        for (auto e : in[i]) {
            int j = e[0], w = e[1];
            if (d[i][st] == d[j][st]+w) {
                adj[j].push_back(i);
            }
        }
    }
    memset(ans, 0, sizeof(ans));
    memset(push, 0, sizeof(push));

    memset(hit, 0, sizeof(hit));
    for (int i = 0; i < n; i++) vis[i] = 0;
    for (int i = 0; i < n; i++) rec(i);


    for (int i = 0; i < n; i++) {
        for (int j : adj[i]) {
            if (vis[st][i]) {
                push[j]++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j]) ans[j] += push[i];
        }
    }
}
void solve(){
    cin >> n >> m;

    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
        d[i][j] = i == j ? 0 : INF;

    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c, --a, --b;
        d[a][b] = d[b][a] = c;
        in[a].push_back({b, c}), in[b].push_back({a, c});
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        get(i);
        for (int j = i+1; j < n; j++) cout << ans[j] << ' ';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}