#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#pragma GCC optimize("unroll-loops")
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
constexpr int N = 2e5+20,mod = 1e9+7 ,inf = 1e9+10,maxm = (1 << 10)+10;
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
ll dlt[N];
inline void solve(){
    int n,m;
    cin >> n >> m;
    rep(i,0,m){
        int x,y,d;
        cin >> x >> y >> d;
        dlt[x] -= d;
        dlt[y] += d;
    }
    set<int> st[2];
    rep(i,1,n+1){
        if (dlt[i] < 0) st[0].insert(i);
        else if (dlt[i]) st[1].insert(i);
    }
    vector<pair<pll,ll> > ve;
    while (!st[0].empty()){
        int i = *(st[0].begin()),j = *(st[1].begin());
        if(-dlt[i] <= dlt[j]){
            ve.pb({{i,j},-dlt[i]});
            dlt[j] += dlt[i];
            st[0].erase(i);
            if (!dlt[j]) st[1].erase(j);
            continue;
        }
        ve.pb({{i,j},dlt[j]});
        dlt[i] += dlt[j];
        st[1].erase(j);
    }
    cout << ve.size() << endl;
    for (auto p : ve) cout << p.X.X << ' ' << p.X.Y << ' ' << p.Y << endl;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    //cin >> T;
    while (T--){
        solve();
    }
    return 0;
}