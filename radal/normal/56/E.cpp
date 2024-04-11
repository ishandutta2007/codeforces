#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse4,avx2")
#pragma GCC optimize("unroll-loops,O2")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define all(x) (x).begin() , (x).end()
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
constexpr int N = 1e5+10,mod = 1e9+7,inf = 1e9+10,base = 233;
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
vector<pair<pll,int> > ve;
int dp[N],seg[N*4],ans[N];
void upd(int l,int r,int p,int x,int v = 1){
    if (r-l == 1){
        seg[v] = x;
        return;
    }
    int m = (l+r) >> 1,u = (v << 1);
    if (p < m) upd(l,m,p,x,u);
    else upd(m,r,p,x,u|1);
    seg[v] = max(seg[u],seg[u|1]);
}
int que(int l,int r,int s,int e,int v = 1){
    if (l >= e || s >= r) return 0;
    if (s <= l && r <= e) return seg[v];
    int m = (l+r) >> 1,u = (v << 1);
    return max(que(l,m,s,e,u),que(m,r,s,e,u|1));
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    rep(i,0,n){
        int x,h;
        cin >> x >> h;
        ve.pb({{x,h},i});
    }
    sort(all(ve));
    dp[n-1] = 1;
    repr(i,n-2,0){
        int x = ve[i].X.X,h = ve[i].X.Y;
        if (x+h > ve[n-1].X.X){
            dp[i] = n-i;
            upd(0,n,i,n);
            continue;
        }
        if (x+h <= ve[i+1].X.X){
            dp[i] = 1;
            upd(0,n,i,i+1);
            continue;
        }
        int r = lower_bound(all(ve),make_pair(make_pair(x+h,0),0))-ve.begin();
        int mx = que(0,n,i+1,r);
        dp[i] = mx-i;
        upd(0,n,i,mx);
    }
    rep(i,0,n) ans[ve[i].Y] = dp[i];
    rep(i,0,n) cout << ans[i] << ' ';
}