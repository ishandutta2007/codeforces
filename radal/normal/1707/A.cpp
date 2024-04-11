#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,avx2")
#pragma GCC optimize("unroll-loops,O3")
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
constexpr int N = 3e5+10,mod = 998244353,inf = 1e9+10;
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
int a[N],pr[N],lz[N*4];
pll seg[N*4];
void build(int l,int r,int v){
    if (r-l == 1){
        seg[v] = {0,l};
        lz[v] = 0;
        return;
    }
    int m = (l+r) >> 1,u = (v << 1);
    build(l,m,u);
    build(m,r,u|1);
    lz[v] = 0;
    seg[v] = max(seg[u],seg[u|1]);
}
void upd(int l,int r,int s,int e,int x,int v = 1){
    if (s <= l && r <= e){
        seg[v].X += x;
        lz[v] += x;
        return;
    }
    if (s >= r || l >= e) return;
    int m = (l+r) >> 1,u = (v << 1);
    if (lz[v]){
        lz[u] += lz[v];
        lz[u|1] += lz[v];
        seg[u].X += lz[v];
        seg[u|1].X += lz[v];
        lz[v] = 0;
    }
    upd(l,m,s,e,x,u);
    upd(m,r,s,e,x,u|1);
    seg[v] = max(seg[u],seg[u|1]);
}
pll que(int l,int r,int s,int e,int v = 1){
    if (s >= r || l >= e) return {-inf,-1};
    if (s <= l && r <= e) return seg[v];
    int m = (l+r) >> 1,u = (v << 1);
    if (lz[v]){
        lz[u] += lz[v];
        lz[u|1] += lz[v];
        seg[u].X += lz[v];
        seg[u|1].X += lz[v];
        lz[v] = 0;
    }
    return max(que(l,m,s,e,u),que(m,r,s,e,u|1));

}
inline void solve(){
    int n,q;
    cin >> n >> q;
    rep(i,0,n){
        cin >> a[i];
        pr[i] = (a[i] <= q);
        if (i) pr[i] += pr[i-1];
    }
    int ans = pr[n-1],j = n,cnt = 0;
    build(0,n,1);
    repr(i,n-1,0){
        upd(0,n,i,i+1,a[i]);
        while (seg[1].X > q){
            cnt++;
            pll p = seg[1];
            upd(0,n,p.Y,p.Y+1,-inf*2);
            upd(0,n,p.Y,n,1);
        }
        if (cnt > q) break;
        if (cnt == q && a[n-1]+q-1 <= q) break;
        if (!i){
            ans = n;
            j = 0;
            break;
        }
        if (ans < pr[i-1]+n-i){
            ans = n-i+pr[i-1];
            j = i;
            continue;
        }
    }
    rep(i,0,j){
        if (a[i] <= q) cout << 1;
        else cout << 0;
    }
    rep(i,j,n) cout << 1;
    cout << endl;
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