#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<ll,int> pll;
const long long int N=1e5+20,mod = 1e9+7,inf=1e18,maxm = (1 << 18);
int poww(ll a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k&1))%mod;
}
ll r[N],h[N],a[N],dp[N],seg[4*N];
int ind[N];
pll b[N];
int n;
void upd(int l,int r,int v,int i,ll val){
    if (r-l == 1){
        seg[v] = val;
        return;
    }
    int m = (l+r)/2;
    if (i < m) upd(l,m,2*v,i,val);
    else upd(m,r,2*v+1,i,val);
    seg[v] = max(seg[2*v],seg[2*v+1]);
}
ll que(int l,int r,int s,int e,int v){
    if (s <= l && r <= e)
        return seg[v];
    if (s >= r || e <= l) return 0;
    int m = (l+r)/2;
    return max(que(l,m,s,e,2*v),que(m,r,s,e,2*v+1));

}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i,0,n){
        cin >> r[i] >> h[i];
        a[i] = r[i]*r[i]*h[i];
        b[i] = {a[i],i};
    }
    long double ans = 0,pi = acos(-1.0);
    sort(b,b+n);
    int p = 0;
    while (p < n && b[p].X == b[0].X){
        dp[p] = b[0].X;
        p++;
    }
    rep(i,0,p) upd(0,n,1,b[i].Y,b[0].X);
    ans = dp[0];
    rep(i,p,n){
        int j = i;
        while (i < n && b[i].X == b[j].X){
            ll g = que(0,n,0,b[i].Y,1);
            dp[i] = b[i].X+g;
            if (dp[i]-ans > 0) ans = dp[i];
            i++;
        }
        rep(k,j,i) upd(0,n,1,b[k].Y,dp[k]);
        i--;
    }
    cout << fixed << setprecision(7) << ans*pi;
    return 0;
}