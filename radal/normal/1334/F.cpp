#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#pragma GCC optimize("unroll-loops")
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
int a[N],b[N],p[N];
ll lz[N*4],seg[N*4];

void build(int l,int r,int v = 1){
    seg[v] = 1ll*inf*inf;
    if (r-l == 1) return;
    int m = (l+r) >> 1,u = (v << 1);
    build(l,m,u);
    build(m,r,u|1);
}

void upd(int l,int r,int s,int e,ll x,int v = 1){
    if (s >= r || l >= e || s >= e) return;
    if (s <= l && r <= e){
        seg[v] += x;
        lz[v] += x;
        return;
    }
    int m = (l+r) >> 1,u = (v << 1);
    if (lz[v]){
        lz[u] += lz[v];
        lz[u|1] += lz[v];
        seg[u] += lz[v];
        seg[u|1] += lz[v];
        lz[v] = 0;
    }
    upd(l,m,s,e,x,u);
    upd(m,r,s,e,x,u|1);
    seg[v] = seg[u|1];
}
ll que(int l,int r,int p,int v = 1){
    if (r-l == 1) return seg[v];
    int m = (l+r) >> 1,u = (v << 1);
    if (lz[v]){
        lz[u] += lz[v];
        lz[u|1] += lz[v];
        seg[u] += lz[v];
        seg[u|1] += lz[v];
        lz[v] = 0;
    }
    if (p < m) return que(l,m,p,u);
    return que(m,r,p,u|1);
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n;
    rep(i,0,n)
        cin >> a[i];
    rep(i,0,n)
        cin >> p[i];
    cin >> m;
    rep(i,0,m)
        cin >> b[i];
    build(0,m);
    ll sum = 0;
    rep(i,0,n){
        int j = lower_bound(b,b+m,a[i])-b;
        sum += p[i];
        upd(0,m,0,j,p[i]);
        if (p[i] < 0)
            upd(0,m,j,m,p[i]);
        if (b[j] != a[i]) continue;
        ll val = que(0,m,j),perv = sum;
        if (j)
            perv = que(0,m,j-1);
        if (perv-p[i] < val)
            upd(0,m,j,j+1,perv-val-p[i]);
    }
    ll ans = que(0,m,m-1);
    if (ans > 1e15){
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;
    cout << ans;
}