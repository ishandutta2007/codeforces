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
void read(){}
template <typename T, typename... Types> 
void read(T& var1, Types&... var2) { 
    fsc(var1);
    read(var2...) ; 
}

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 1e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MAXK = 17, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB), MOD = 1e9+7;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 1e18+10;

int n, m, q;
vector<int> adj[MAXN];
ll ans=0, in[MAXN], out[MAXN];

void solve(){
    //sum of indeg[x]*outdeg[x];
    //each operation, reverse all edges leading out
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b, --a, --b; if (a > b) swap(a, b);
        adj[a].push_back(b); out[a]++; in[b]++;
    }
    for (int i = 0; i < n; i++) ans += in[i]*out[i];
    cout << ans << '\n';
    cin >> q;
    while (q--){
        int x; cin >> x, --x;
        ans -= in[x]*out[x]; in[x]+=out[x]; out[x]=0;
        for (auto nxt : adj[x]){
            ans -= in[nxt]*out[nxt];
            in[nxt]--; out[nxt]++;
            ans += in[nxt]*out[nxt];
            adj[nxt].push_back(x);
        }
        adj[x].clear();
        cout << ans << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}