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
const int MAXN = 1e5+10, MAXQ = 3e5+10, MAXL = 18, ALP = 26, MOD = 998244353, MAXK = 17,  MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const int INF = 1e9+10;

int n, m, sq = 0, depth[MAXN], par[MAXN];
vector<int> adj[MAXN];
bool mark[MAXN];

void dfs(int c=0, int d=0) {
    depth[c] = d;
    for (auto nxt : adj[c]) {
        if (depth[nxt] == -1) {
            par[nxt] = c;
            dfs(nxt, d+1);
        } else {
            if (depth[c]-depth[nxt]+1 >= sq) {
                cout << "2\n";
                cout << depth[c]-depth[nxt]+1 << '\n';
                while (1) {
                    cout << c+1 << ' ';
                    if (c == nxt) break;
                    c = par[c];
                }
                exit(0);
            }
        }
    }
    if (!mark[c]) {
        for (auto nxt : adj[c]) {
            mark[nxt] = 1;
        }
    }
}
void solve(){
    cin >> n >> m;
    while (sq*sq < n) sq++;

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    memset(depth, -1, sizeof(depth));
    dfs();

    vector<int> ans;
    for (int i = 0; i < n; i++) if (!mark[i]) ans.push_back(i);
    if (sz(ans) < sq) {
        cout << n << ' ' << sq << ' ' << sz(ans) << endl;
        assert(false);
    }
    cout << "1\n";
    for (int i = 0; i < sq; i++) cout << ans[i]+1 << ' ';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}