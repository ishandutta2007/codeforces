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
constexpr int N = 5e5+10,mod = 1e9+7,inf = 1e9+10;
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
pll seg[N*4][2];
int a[N];
bool lz[N*4];

void build(int l,int r,int v = 1){
    seg[v][0].X = l;
    seg[v][0].Y = r-1;
    seg[v][1].X = -1;
    seg[v][1].Y = -1;
    if (r-l == 1) return;
    int m = (l+r) >> 1,u = (v << 1);
    build(l,m,u);
    build(m,r,u|1);
}
int que(int l,int r,int s,bool f,int v = 1){
    if (s <= l) return seg[v][f].X;
    if (s >= r) return -1;
    int m = (l+r) >> 1,u = (v << 1);
    if (lz[v]){
        lz[u] ^= 1;
        lz[u|1] ^= 1;
        swap(seg[u][0],seg[u][1]);
        swap(seg[u|1][0],seg[u|1][1]);
        lz[v] = 0;
    }
    if (s >= m) return que(m,r,s,f,u|1);
    int x = que(l,m,s,f,u);
    if (x != -1) return x;
    return que(m,r,s,f,u|1);
}
void upd(int l,int r,int s,int e,int v = 1){
    if (s <= l && r <= e){
        lz[v] ^= 1;
        swap(seg[v][0],seg[v][1]);
        return;
    }
    if (s >= r || l >= e) return;
    int m = (l+r) >> 1,u = (v << 1);
    if (lz[v]){
        lz[u] ^= 1;
        lz[u|1] ^= 1;
        swap(seg[u][0],seg[u][1]);
        swap(seg[u|1][0],seg[u|1][1]);
        lz[v] = 0;
    }
    upd(l,m,s,e,u);
    upd(m,r,s,e,u|1);
    if (seg[u][0].X != -1)
        seg[v][0].X = seg[u][0].X;
    else
        seg[v][0].X = seg[u|1][0].X;
    if (seg[u][1].X != -1)
        seg[v][1].X = seg[u][1].X;
    else
        seg[v][1].X = seg[u|1][1].X;
    if (seg[u|1][0].Y != -1)
        seg[v][0].Y = seg[u|1][0].Y;
    else
        seg[v][0].Y = seg[u][0].Y;
    if (seg[u|1][1].Y != -1)
        seg[v][1].Y = seg[u|1][1].Y;
    else
        seg[v][1].Y = seg[u][1].Y;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    build(0,N,1);
    int n,q;
    cin >> n >> q;
    rep(i,0,n){
        cin >> a[i];
        int j = que(0,N,a[i],0,1);
        upd(0,N,a[i],j+1);
    }
    while (q--){
        int i,l;
        cin >> i >> l;
        i--;
        int j = que(0,N,a[i],1,1);
        upd(0,N,a[i],j+1);
        a[i] = l;
        j = que(0,N,a[i],0,1);
        upd(0,N,a[i],j+1);
        cout << seg[1][1].Y << endl;
    }
    return 0;
}