#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define all(x) x.begin(),x.end() 
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;

constexpr int N = 4e5+20,mod = 1e9+7,inf = 1e9+10,maxm = (1 << 18)+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
 
inline int poww(ll a,ll k,ll m){
    if (k < 0) return 0;
    ll z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%m;
        a = 1ll*a*a%m;
        k /= 2;
    }
    return z;
}
int x[N],n,v,lm;
int t[N],dp[N],fen[N];
inline void upd(int r,int x){
    for(; r < lm; r |= (r+1)){
        fen[r] = max(fen[r],x);
    }
}
inline int que(int l){
    int ans = -inf;
    for (; l >= 0; l = (l&(l+1))-1)
        ans = max(ans,fen[l]);
    return ans;
}
void solve(int l,int r){
    if (r-l == 1){
        if (1ll*v*t[l] >= abs(x[l])) dp[l] = max(1,dp[l]);
        return;
    }
    int m = (l+r) >> 1;
    solve(l,m);
    vector<ll> ve,ve2;
    vector<pll> b;
    rep(i,l,r){
        ve.pb(1ll*t[i]*v-x[i]);
        ve2.pb(1ll*t[i]*v+x[i]);
        b.pb({x[i],i});
    }
    sort(all(ve));
    sort(all(ve2));
    sort(all(b));
    lm = r-l;
    rep(i,0,lm){
        int j = lower_bound(all(ve),1ll*t[b[i].Y]*v-x[b[i].Y])-ve.begin();
        if (b[i].Y < m){
            upd(j,dp[b[i].Y]);
        }
        else{
            dp[b[i].Y] = max(dp[b[i].Y],que(j)+1);
        }
    }
    rep(i,0,lm) fen[i] = -inf;
    repr(i,lm-1,0){
        int j = lower_bound(all(ve2),1ll*t[b[i].Y]*v+x[b[i].Y])-ve2.begin();
        if (b[i].Y < m){
            upd(j,dp[b[i].Y]);
        }
        else{
            dp[b[i].Y] = max(dp[b[i].Y],que(j)+1);
        }
    }
    rep(i,0,lm) fen[i] = -inf;
    solve(m,r);
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    cin >> n >> v;
    rep(i,0,n) cin >> t[i];
    rep(i,0,n){
        cin >> x[i];
        dp[i] = -inf;
        fen[i] = -inf;
    }
    solve(0,n);
    int ans = 0;
    rep(i,0,n){
        ans = max(ans,dp[i]);
    }
    cout << ans;
}