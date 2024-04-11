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
constexpr int N = 5e5+20,mod = 1e9+7 ,inf = 1e9+10,maxm = (1 << 10)+10;
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
ll pre[N];
int a[N],seg[N*4][2],dp[N],lz[N*4];
void build(int l,int r,int v = 1){
    seg[v][0] = seg[v][1] = -inf;
    lz[v] = 0;
    if (r-l == 1) return;
    int m = (l+r) >> 1,u = (v << 1);
    build(l,m,u);
    build(m,r,u|1);
}
void upd(int l,int r,int p,int x,int v = 1){
    if (r-l == 1){
        seg[v][0] = seg[v][1] = x;
        return;
    }
    int m = (l+r) >> 1,u =(v << 1);
    if (lz[v]){
        lz[u] += lz[v];
        lz[u|1] += lz[v];
        seg[u][0] += lz[v];
        seg[u|1][0] += lz[v];
        lz[v] = 0;
    }
    if (p < m) upd(l,m,p,x,u);
    else upd(m,r,p,x,u|1);
    seg[v][0] = max(seg[u][0],seg[u|1][0]);
    seg[v][1] = max(seg[u][1],seg[u|1][1]);
}
int que(int l,int r,int s,int e,bool f,int v = 1){
    if (l >= e || s >= e || s >= r) return -inf;
    if (s <= l && r <= e){
        return seg[v][f];
    }
    int m = (l+r) >> 1,u =(v << 1);
    if (lz[v]){
        lz[u] += lz[v];
        lz[u|1] += lz[v];
        seg[u][0] += lz[v];
        seg[u|1][0] += lz[v];
        lz[v] = 0;
    }
    return max(que(l,m,s,e,f,u),que(m,r,s,e,f,u|1));
}
inline void solve(){
    int n;
    cin >> n;
    build(0,n+1);
    vector<pair<ll,int> > ve;
    ve.pb({0,0});
    rep(i,1,n+1){
        cin >> a[i];
        pre[i] = pre[i-1]+a[i];
        ve.pb({pre[i],i});
    }
    sort(ve.begin(),ve.end());

    int y = lower_bound(ve.begin(),ve.end(),make_pair(0ll,0))-ve.begin();;
    upd(0,n+1,y,0);
    rep(i,1,n+1){
        dp[i] = dp[i-1];
        if (a[i] < 0) dp[i]--;
        else if (a[i] > 0) dp[i]++;
        int j = lower_bound(ve.begin(),ve.end(),make_pair(pre[i],n+2))-ve.begin();
        int k = lower_bound(ve.begin(),ve.end(),make_pair(pre[i],0))-ve.begin();
        int ind = lower_bound(ve.begin(),ve.end(),make_pair(pre[i],i))-ve.begin();
        dp[i] = max(dp[i],que(0,n+1,0,k,0)+1);
        dp[i] = max(dp[i],que(0,n+1,k,j,1));
        upd(0,n+1,ind,dp[i]-1);
        lz[1]++;
        seg[1][0]++;
        //debug(dp[i]);
    }
    cout << dp[n] << endl;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        solve();
    }
    return 0;
}