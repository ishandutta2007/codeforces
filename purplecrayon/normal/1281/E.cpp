#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using omset=tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;


#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 2e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 30, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

struct TestCase {
    int n, sub[MAXN];
    ll w[MAXN];
    vector<pair<int, ll>> adj[MAXN];
    int dfs(int c=0, int p=-1){
        sub[c]=1;
        for (auto nxt : adj[c]) if (nxt.first != p) sub[c] += dfs(nxt.first, c), w[nxt.first]=nxt.second;
        return sub[c];
    }
    void solve(){
        cin >> n; n *= 2;
        for (int i = 0; i < n-1; i++){
            int a, b; ll t; cin >> a >> b >> t, --a, --b;
            adj[a].push_back({b, t}), adj[b].push_back({a, t});
        }
        dfs(); ll ans1=0, ans2=0;
        for (int i = 1; i < n; i++) if ((sub[i]&1)||((n-sub[i])&1)) ans1 += w[i];
        for (int i = 1; i < n; i++){
            ans2 += min(sub[i], n-sub[i])*w[i];
        }
        cout << ans1 << ' ' << ans2 << '\n';
    }
};

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1; cin >> t; 
    while (t--){ TestCase tc; tc.solve(); }
}