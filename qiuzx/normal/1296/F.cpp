#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
typedef pair<int,pll> plll;
typedef pair<pll,pll> ppll;
typedef long double ld;
 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fst first
#define snd second
#define ins insert
#define pb push_back
template< typename T,typename V>ostream &operator<< (ostream &out,const pair<T,V> x){ out << "{" << x.fst << " : " << x.snd << "}"; return out;}template< typename T>ostream &operator<< (ostream &out,const set<T> x){ for(auto &it : x){ out << it << " "; } return out;}template< typename T>ostream &operator<< (ostream &out,const multiset<T> x){ for(auto &it : x){ out << it << " "; } return out;}template< typename T,typename V>ostream &operator<< (ostream &out,const map<T,V> x){ for(auto &it : x){ out << "[" << it.fst << "]" << " = " << it.snd << "\n"; } return out;}template< typename T>ostream &operator<< (ostream &out,const vector<T> x){ for(int i = 0;i < x.size() - 1; ++i){ out << x[i] << " "; } out << x.back(); return out;}template< typename T>ostream &operator<< (ostream &out,const vector<vector<T> > x){ for(int i = 0;i < x.size() - 1; ++i){ out << "[" << i << "]" << " = {" << x[i] << "}\n"; } out << "[" << x.size() - 1 << "]" << " = {" << x.back() << "}\n"; return out;}
 
const ll N = 5005;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
ll dp[N][62];
ll a[N];
ll h[N];
vector<ll> g[N];
ll tin[N],tout[N],timer = 0;
void dfs(ll v,ll p){
    h[v] = h[p] + 1;
    tin[v] = timer++;
    dp[v][0] = p;
    for(ll i = 1;i < 62; ++i)dp[v][i] = dp[dp[v][i - 1]][i - 1];
    for(auto &it : g[v]){
        if(it == p)continue;
        dfs(it,v);
    }
    tout[v] = timer++;
}
bool cmp(ll x,ll y){
    return tin[x] <= tin[y] && tout[y] <= tout[x];
}
ll lca(ll x,ll y){
    if(cmp(x,y))return x;
    if(cmp(y,x))return y;
    for(ll i = 60;i >= 0; --i){
        if(!cmp(dp[x][i],y))x = dp[x][i];
    }
    return dp[x][0];
}
bool check(ll x,ll y,ll val){
    if(h[x] < h[y])return false;
    while(x != y){
        if(a[x] == 0 || a[x] == val)return true;
        x = dp[x][0];
        if(x == 0 || x == 1)break;
    }
    return false;
}
void upd(ll x,ll y,ll val){
    if(h[x] < h[y])return;
    while(x != y){
        if(a[x] == 0)a[x] = val;
        x = dp[x][0];
        if(x == 0 || x == 1)break;
    }
}
mt19937_64 rng(time(0));
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    ll n;
    cin >> n;
    vector<pll> rd;
    for(ll i = 1;i < n; ++i){
        ll u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
        rd.pb({u,v});
    }
    ///ll rnd = rng() % n + 1;
    dfs(1,1);
    vector<plll> ar;
    ll m;
    cin >> m;
    for(ll i = 0;i < m; ++i){
        ll x,y,z;
        cin >> x >> y >> z;
        ar.pb({z,{x,y}});
    }
    sort(rall(ar));
    for(auto &it : ar){
        ll x = it.snd.fst,y = it.snd.snd;
        ll val = it.fst;
        ll lc = lca(x,y);
        if(!check(x,lc,val) && !check(y,lc,val)){
            cout << -1;
            return 0;
        }
        upd(x,lc,val);
        upd(y,lc,val);
    }
    for(auto &it : rd){
        ll x = it.fst,y = it.snd;
        if(h[x] < h[y])swap(x,y);
        if(a[x] != 0)cout << a[x] << " ";else cout << "1000000 ";
    }
    return 0;
}