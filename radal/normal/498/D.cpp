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
constexpr int N = 1e5+10,mod = 777777777,inf = 1e9+10;
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
int seg[N*4][60];
int a[N];

void build(int l,int r,int v = 1){
    if (r-l == 1){
        rep(i,0,60){
            if (i%a[l])
                seg[v][i] = 1;
            else
                seg[v][i] = 2;
        }
        return;
    }
    int m = (l+r) >> 1,u = (v << 1);
    build(l,m,u);
    build(m,r,u|1);
    rep(i,0,60){
        int t = (i+seg[u][i])%60;
        seg[v][i] = seg[u][i]+seg[u|1][t];
    }
}

void upd(int l,int r,int p,int x,int v = 1){
    if (r-l == 1){
        a[l] = x;
        rep(i,0,60){ 
            if (i%a[l])
                seg[v][i] = 1;
            else
                seg[v][i] = 2;
        }
        return;
    }
    int m = (l+r) >> 1,u = (v << 1);
    if (p < m) upd(l,m,p,x,u);
    else upd(m,r,p,x,u|1);
    rep(i,0,60){
        int t = (i+seg[u][i])%60;
        seg[v][i] = seg[u][i]+seg[u|1][t];
    }
}

int que(int l,int r,int s,int e,int t,int v = 1){
    if (l == s && r == e){
        return seg[v][t];
    }
    int m = (l+r) >> 1,u = (v << 1);
    if (e <= m) return que(l,m,s,e,t,u);
    if (s >= m) return que(m,r,s,e,t,u|1);
    int ti = que(l,m,s,m,t,u);
    return ti+que(m,r,m,e,(ti+t)%60,u|1);
}

int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n,q;
    cin >> n;
    rep(i,0,n) cin >> a[i];
    build(0,n);
    cin >> q;
    while (q--){
        char c;
        int x,y;
        cin >> c >> x >> y;
        if (c == 'C'){
            x--;
            upd(0,n,x,y);
            continue;
        }
        cout << que(0,n,x-1,y-1,0) << endl;
    }
}