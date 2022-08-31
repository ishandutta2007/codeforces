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
const int MAXN = 5e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 1e18+10;

int n, k;
vector<pair<int, ll>> adj[MAXN];
ll dp[MAXN][2];

void dfs(int c=0, int p=-1){
    for (auto nxt : adj[c]) if (nxt.first != p) dfs(nxt.first, c);
    for (int r = 0; r < 2; r++){
        int left=k-r;
        //going to connect to at most left
        ll sm=0; vector<ll> v;
        for (auto nxt : adj[c]) if (nxt.first != p) sm += dp[nxt.first][0], v.push_back(dp[nxt.first][1]-dp[nxt.first][0]+nxt.second);
        sort(v.rbegin(), v.rend());
        for (int i = 0; i < left && i < sz(v); i++) 
            if (v[i] > 0) sm += v[i];
            else break;
        dp[c][r] = sm; 
    }
}
void solve(){
    //i can choose at most k edges out of each thing
    //need to find maximum weight
    //dp[n][2] -> ith vertex if i can connect to it (from par)
    cin >> n >> k; for (int i = 0; i < n; i++) adj[i].clear();
    for (int i = 0; i < n-1; i++){
        int a, b; ll w; cin >> a >> b >> w, --a, --b;
        adj[a].push_back({b, w}), adj[b].push_back({a, w});
    }
    dfs();
    cout << dp[0][0] << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t; 
    while (t--) solve();
}