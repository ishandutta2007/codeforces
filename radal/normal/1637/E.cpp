#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx2,fma")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
const long long int N = 3e5+20,mod = 1e9+7,inf = 1e9+10,maxm= (1 << 21);
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}

inline int poww(int a,int k){
    if (k < 0) return 0;
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%mod;
        a = 1ll*a*a%mod;
        k >>= 1;
    }
    return z;
}
map<int,int> mp;
int a[N];
vector<int> ve[N],ind;
bool cmp(pll u,pll v){
    if (u.X != v.X)
        return (u.X > v.X);
    if (mp[u.Y] != mp[v.Y])
        return (mp[u.Y] > mp[v.Y]);
    return (u.Y > v.Y);
}
inline void solve(){
    int n,m;
    cin >> n >> m;
    mp.clear();
    rep(i,0,n){
        ve[i+1].clear();
        cin >> a[i];
        mp[a[i]]++;
    }
    ind.clear();
    sort(a,a+n);
    rep(i,0,n){
        if (i && a[i] == a[i-1]) continue;
        int t = mp[a[i]];
        if (ve[t].empty()) ind.pb(t);
        ve[t].pb(a[i]);
    }
    vector<pll> st;
    rep(i,0,m){
        int x,y;
        cin >> x >> y;
        if (x > y) swap(x,y);
        st.pb({x,y});
    }
    sort(st.begin(),st.end(),cmp);
    sort(ind.begin(),ind.end());
    reverse(ind.begin(),ind.end());
    ll ans = 0;
    int po = 0;
    repr(i,n-1,0){
        if (i && a[i] == a[i-1]) continue;
        int t = mp[a[i]];
        for (int u : ind){
            int sz = ve[u].size();
            repr(j,sz-1,0){
                if (a[i] >= ve[u][j]) break;
                while (po < m && cmp(st[po],make_pair(a[i],ve[u][j]))){
                    po++;
                }
                if (po < m && st[po] == make_pair(a[i],ve[u][j])){
                    po++;
                    continue;
                }
                ans = max(ans,1ll*(a[i]+ve[u][j])*(u+t));
                break;
                
            }
        }
    }
    cout << ans << endl; 
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        solve();
    }
}