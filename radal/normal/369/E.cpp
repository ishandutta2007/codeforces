#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
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
const long long int N=1e6+20,mod = 1e9+7,inf=1e18,dlt = 12250,maxm = 2e6;
int poww(ll a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k&1))%mod;
}
vector<int> a[N];
vector<pll> b[N];
int ans[N];
int seg[4*N];
void upd(int l, int r, int v, int p){
    if(r-l == 1){
        seg[v]++;
        return;
    }
    int m = (l+r)/2;
    seg[v]++;
    if (p < m)
        upd(l,m,2*v,p);
    else
        upd(m,r,2*v+1,p);
}
int get(int l,int r,int s,int e,int v){
//    debug(s);
  //  debug(e);
    if (l == s && e == r)
        return seg[v];
    int m = (l+r)/2;
    if (e <= m) return get(l,m,s,e,2*v);
    if (s >= m) return get(m,r,s,e,2*v+1);
    return get(l,m,s,m,2*v)+get(m,r,m,e,2*v+1);
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin >> n >> m;
    rep(i,0,n){
        int l,r;
        cin >> l >> r;
        a[r].pb(l);
    }
    rep(i,0,m){
        int cnt,st = 0;
        cin >> cnt;
        rep(j,0,cnt){
            int x;
            cin >> x;
            if (st <= x-1) b[x-1].pb({st,i});
            st = x+1;
        }
        if (st <= 1e6)
            b[int(1e6)].pb({st,i});
    }
    rep(i,1,1e6+1){
        for(int u : a[i])
            upd(0,1e6+1,1,u);
        for (pll u : b[i])
            ans[u.Y] += get(0,1e6+1,u.X,i+1,1);
        
    }
    rep(i,0,m){
        cout << n-ans[i] << endl;
    }
    return 0;
}