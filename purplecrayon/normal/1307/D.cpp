#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void fsc(int &x){
    register int c;
    x = 0; c=getchar();
    for(;(c>47 && c<58);c=getchar())
        x = (x<<1)+(x<<3)+c-48;
}

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 2e5+10, MAXM = 2e5+10, MAXL = 20, ALP = 26, MOD = 998244353, MAXK = 2e5+10, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB), MAXP = 2e5+10;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    int n, m, k; fsc(n), fsc(m), fsc(k);
    vector<int> a(k); for (auto& it : a) fsc(it), --it;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++){
        int a, b; fsc(a), fsc(b), --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    auto bfs = [&](vector<ll>& d, int s){
        fill(d.begin(), d.end(), 1e9); d[s] = 0;
        queue<int> q; q.push(s);
        while (q.size()){
            auto c = q.front(); q.pop();
            for (auto nxt : adj[c]) if (d[nxt] >= 1e9){
                d[nxt] = d[c]+1;
                q.push(nxt);
            }
        }
    };
    vector<ll> d1(n), dn(n); bfs(d1, 0), bfs(dn, n-1);
    sort(a.begin(), a.end(), [&](int x, int y){
        return d1[x]-dn[x] < d1[y]-dn[y];
    });
    ll mx = -1e18, ans = -1e18;
    for (int i = 0; i < k; i++){
        // cout << a[i] << ' ' << d1[a[i]] << ' ' << dn[a[i]] <<' ' << mx <<  '\n';
        ans = max(ans, dn[a[i]]+mx+1);
        mx = max(mx, d1[a[i]]);
    }
    cout << min(ans, d1[n-1]) << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}