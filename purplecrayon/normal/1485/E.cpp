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
const int MAXN = 2e5+10, MAXM = 40, MAXL = 20, ALP = 20, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 1e2+10, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

int n, depth[MAXN];
vector<int> adj[MAXN], lev[MAXN];
ll a[MAXN], dp[MAXN], pd[MAXN];

void dfs(int c=0, int d=0){
    depth[c]=d, lev[d].push_back(c);
    for (auto nxt : adj[c]) dfs(nxt, d+1);
}
void solve(){
    cin >> n;
    for (int i = 1; i < n; i++){
        int p; cin >> p, --p;
        adj[p].push_back(i);
    }
    fill(a, a+n, 0ll);
    for (int i = 1; i < n; i++) cin >> a[i];
    dfs();

    fill(pd, pd+n, 0ll); fill(dp, dp+n, 0ll);
    for (int i = n-1; i >= 0; i--) if (sz(lev[i])) {
        for (auto c : lev[i]) 
            for (auto nxt : adj[c]) pd[c] = max(pd[c], dp[nxt]);

        sort(lev[i].begin(), lev[i].end(), [&](auto x, auto y){
            return a[x] < a[y];
        });

        {
            ll mx1=-1e18, mx2=-1e18;
            for (int j = 0; j < sz(lev[i]); j++){
                auto c=lev[i][j];
                mx1 = max(mx1, -a[c]), mx2 = max(mx2, pd[c]-a[c]);

                dp[c] = max({dp[c], mx1+a[c]+pd[c], mx2+a[c]});
            }
        }
        {
            ll mx1=-1e18, mx2=-1e18;
            for (int j = sz(lev[i])-1; j >= 0; j--){
                auto c=lev[i][j];
                mx1 = max(mx1, a[c]), mx2 = max(mx2, pd[c]+a[c]);

                dp[c] = max({dp[c], mx1-a[c]+pd[c], mx2-a[c]});
            }
        }
    }
    for (int i = 0; i < n; i++) lev[i].clear(), adj[i].clear();
    cout << pd[0] << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    cin >> t_c;
    while (t_c--) solve();
}