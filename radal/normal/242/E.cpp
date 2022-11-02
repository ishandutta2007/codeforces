#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
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
const long long int N = 1e5+20,mod = 1e9+7,inf=1e9,maxm = 1e6+1;
int seg[4*N][21],a[N],n,lz[4*N][21];
void build(int l,int r,int v,int i){
    if (r-l == 1){
        int j = (1 << i);
        if (a[l]&j) seg[v][i] = 1;
        else seg[v][i] = -1;
        return;
    }
    int m = (l+r)/2;
    build(l,m,2*v,i);
    build(m,r,2*v+1,i);
    seg[v][i] = seg[2*v][i]+seg[2*v+1][i];
}
int que(int l,int r,int s,int e,int v,int i){ 
    if (l >= s && e >= r)
        return (r-l+seg[v][i])/2;
    if (r <= s || e <= l) return 0;
    int m = (l+r)/2,u = 2*v;
    if (lz[v][i]){
        lz[u][i] = 1-lz[u][i];
        seg[u][i] = -seg[u][i];
        lz[u|1][i] = 1-lz[u|1][i];
        seg[u|1][i] = -seg[u|1][i];
        lz[v][i] = 0;
    }
    return que(l,m,s,e,u,i)+que(m,r,s,e,u|1,i);
}
void upd(int l,int r,int s,int e,int v,int i){
    if (l >= s && e >= r){
        seg[v][i] *= (-1);
        lz[v][i] = 1-lz[v][i];
        return;
    }
    if (l >= e || s >= r) return;
    int m = (l+r)/2,u = 2*v;
    if (lz[v][i]){
        lz[u][i] = 1-lz[u][i];
        seg[u][i] = -seg[u][i];
        lz[u|1][i] = 1-lz[u|1][i];
        seg[u|1][i] = -seg[u|1][i];
        lz[v][i] = 0;
    }
    upd(l,m,s,e,u,i);
    upd(m,r,s,e,u+1,i);
    seg[v][i] = seg[u][i]+seg[u|1][i];
}
inline ll ans(int l,int r){
    ll out = 0;
    rep(i,0,21)
        out += 1ll*que(0,n,l,r,1,i)*(1 << i);
    return out;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    cin >> n;
    rep(i,0,n) cin >> a[i];
    rep(i,0,21)
        build(0,n,1,i);
    int q;
    cin >> q;
    rep(i,0,q){
        int t,l,r;
        cin >> t >> l >> r;
        l--;
        if (t == 1){
            cout << ans(l,r) << endl;
            continue;
        }
        int x;
        cin >> x;
        rep(i,0,21)
            if (x&(1 << i)) upd(0,n,l,r,1,i);
        
    }
    return 0;
}