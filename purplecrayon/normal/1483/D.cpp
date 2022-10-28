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
const int MAXN = 6e2+10, MAXQ = MAXN*MAXN, MAXL = 20, ALP = 26, MOD = 998244353, MAXK = 17, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 1e18+10;
 
int n, m;
ll d[MAXN][MAXN], con[MAXN][MAXN];
vector<pair<int, ll>> adj[MAXN];
vector<pair<int, ll>> qa[MAXN];

void solve(){
    cin >> n >> m;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) d[i][j] = (i==j?0:INF);
    for (int i = 0; i < m; i++) {
        int a, b; ll w; cin >> a >> b >> w, --a, --b;
        d[a][b] = d[b][a] = w;

        adj[a].push_back({b, w}), adj[b].push_back({a, w});
    }


    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
            }
        }
    }
    //for (int i = 0; i < n; i++) { for (int j = 0; j < n; j++) cerr << d[i][j] << ' '; cerr << endl; }

    int q; cin >> q;
    while (q--){
        int a, b; ll w; cin >> a >> b >> w, --a, --b;
        qa[a].push_back({b, w}), qa[b].push_back({a, w});
    }
    memset(con, -1, sizeof(con));
    for (int i = 0; i < n; i++) {
        for (auto j : qa[i]) {
            for (int k = 0; k < n; k++) con[i][k] = max(con[i][k], j.second-d[j.first][k]);
        }
        //for (int k = 0; k < n; k++) cerr << "h: " << i << ' ' << k << ' ' << con[i][k] << endl;
    }
    int ans=0;
    for (int i = 0; i < n; i++) {
        for (auto nxt : adj[i]) {
            int j = nxt.first;
            ll w = nxt.second;
            if (j < i) continue; //no double counting

            bool bad=1;
            for (int k = 0; k < n && bad; k++) {
                bad &= d[i][k]+w>con[k][j];
                //if (!bad) cerr << i << ' ' << j << ' ' << k << ' ' << d[i][k] << ' ' << w << ' ' << con[k][j] << endl;
            }
            ans += !bad;
        }
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}