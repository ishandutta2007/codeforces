#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,sse4,avx2")
//#pragma GCC optimize("unroll-loops,O2")
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
constexpr int N = 1e5+10,mod = 1e9+7,inf = 1e9+10;
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
int a[N],b[N];
pll seg[N*4];

void build(int l,int r,int v = 1){
    seg[v] = {-1,-1};
    if (r-l == 1) return;
    int m = (l+r) >> 1,u = (v << 1);
    build(l,m,u);
    build(m,r,u|1);
}
void upd(int l,int r,int s,int e,pll p,int v = 1){
    if (l >= e || s >= r || s >= e) return;
    if (s <= l && r <= e){
        seg[v] = p;
        return;
    }
    int u = (v << 1),m = (l+r) >> 1;
    if (seg[v].X != -1){
        seg[u] = seg[v];
        seg[u|1] = seg[v];
        seg[v] = {-1,-1};
    }
    upd(l,m,s,e,p,u);
    upd(m,r,s,e,p,u|1);
}
pll que(int l,int r,int p,int v = 1){
    if (r-l == 1) return seg[v];
    if (seg[v].X != -1) return seg[v];
    int u = (v << 1),m = (l+r) >> 1;
    if (p < m) return que(l,m,p,u);
    else return que(m,r,p,u|1);
}
int main(){
   ios :: sync_with_stdio(0); cin.tie(0);
   int n,q;
   cin >> n >> q;
   rep(i,0,n) cin >> a[i];
   rep(i,0,n) cin >> b[i];
   build(0,n);
   while (q--){
       int ty;
       cin >> ty;
       if (ty == 1){
           int k,x,y;
           cin >> x >> y >> k;
           x--;
           y--;
           upd(0,n,y,y+k,{x,y});
           continue;
       }
       int x;
       cin >> x;
       x--;
       pll p = que(0,n,x);
       if (p.X == -1){
           cout << b[x] << endl;
           continue;
       }
       cout << a[p.X+x-p.Y] << endl;
   }
   return 0;
}