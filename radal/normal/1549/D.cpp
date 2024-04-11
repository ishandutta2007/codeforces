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
const long long int N=2e5+20,mod = 1e9+7,inf=1e18,maxm = (1 << 18);
int poww(ll a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k&1))%mod;
}
ll a[N],seg[4*N];
void build(int l,int r,int v){
    if(r-l == 1){
        seg[v] = -1;
        return;
    }
    int m = (l+r)/2;
    build(l,m,2*v);
    build(m,r,2*v+1);
    ll p=seg[2*v],q = seg[2*v+1];
    ll w = a[m],u = a[m-1];
    if (u < w) swap(u,w);
    if (p == -1 && q == -1){
        seg[v] = u-w;
        return;
    }
    if (p == -1) seg[v] = q;
    else if (q == -1) seg[v] = p;
    else seg[v] = gcd(p,q);
    seg[v] = gcd(seg[v],u-w);
}
ll que(int l,int r,int s,int e,int v){
    if (l == s && e == r) return seg[v];
    int m = (l+r)/2;
    if (e <= m) return que(l,m,s,e,2*v);
    if (s >= m) return que(m,r,s,e,2*v+1);
    ll p = que(l,m,s,m,2*v),q = que(m,r,m,e,2*v+1);
    ll u=a[m-1],w = a[m],g;
    if (w < u) swap(u,w);
    if (p == -1 && q == -1) return w-u;
    if (p == -1) return gcd(q,w-u);
    else if (q == -1) return gcd(p,w-u);
    g = gcd(p,q);
    g = gcd(w-u,g);
    return g;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T=1;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        rep(i,0,n){
            cin >> a[i];
        }
        build(0,n,1);
        int ans = 1,p=0;
        rep(i,1,n){
            while (p < i && que(0,n,p,i+1,1) == 1) p++;
            ans = max(ans,i+1-p);
        }
        cout << ans << endl;
    }
    return 0;
}