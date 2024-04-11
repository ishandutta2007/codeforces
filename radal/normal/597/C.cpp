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
typedef pair<int,int> pll;
const long long int N=1e5+20,mod = 1e9+7,inf=1e18,maxm = (1 << 18);
int poww(ll a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k&1))%mod;
}
ll dp[N][20];
ll seg[4*N][20];
int a[N];
void upd (int l,int r,int p,ll val,int k,int v){
    seg[v][k] += val;
    if (r-l == 1) return;
    int m = (l+r+1)/2;
    if (p < m)
        upd(l,m,p,val,k,2*v);
    else
        upd(m,r,p,val,k,2*v+1);
    
}
ll get(int l,int r,int s,int e,int v,int k){

    if (l >= s && e >= r)
        return seg[v][k];
    if (r <= s || e <= l) return 0;
    int m = (l+r+1)/2;
    return get(l,m,s,e,2*v,k)+get(m,r,s,e,2*v+1,k);
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin >> n >> k;
    rep(i,0,n)
        cin >> a[i];
    dp[0][0] = 1;
    dp[0][1] = 1;
    upd(0,n,a[0]-1,1,1,1);
    upd(0,n,0,1,0,1);
    rep(i,1,n){
        repr(j,11,1){
            ll g = get(0,n,0,a[i],1,j-1);
            dp[i][j] = dp[i-1][j]+g;
            upd(0,n,a[i]-1,g,j,1);
        }
    }
    cout << dp[n-1][k+1];
    return 0;
}