#include <bits/stdc++.h>
#pragma GCC optimize("O3,no-stack-protector,unroll-loops")
#pragma GCC target("avx2,fma")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
typedef pair<long double,long double> pld;
const long long int N = 1e5+10,mod = 1e9+7,inf = 1e9,sq = 500,maxm = 5e3+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
inline int poww(int n,int k){
    int c = 1;
    while (k){
        if (k&1) c = (1ll*c*n)%mod;
        n = (1ll*n*n)%mod;
        k >>= 1;
    }
    return c;
}
string s;
int n,q;
int seg[N*4][4][4];
void build (int l,int r,int v){
    if (r-l == 1){
        if (s[l] == 'a'){
            rep(i,0,4)
                rep(j,i+1,4)
                    seg[v][i][j] = inf;
            seg[v][0][1] = 0;
            seg[v][0][0] = 1;
            return;
        }
        if (s[l] == 'b'){
            rep(i,0,4)
                rep(j,i+1,4)
                    seg[v][i][j] = inf;
            seg[v][1][2] = 0;
            seg[v][1][1] = 1;
            return;
        }
        rep(i,0,4)
            rep(j,i+1,4)
                seg[v][i][j] = inf;
        seg[v][2][3] = 0;
        seg[v][2][2] = 1;
        return;
    }
    int m = (l+r) >> 1,u = (v << 1);
    build(l,m,u);
    build(m,r,u|1);
    rep(i,0,4){
        rep(j,i,4){
            seg[v][i][j] = inf;
            rep(k,i,j+1)
                seg[v][i][j] = min(seg[v][i][j],seg[u][i][k]+seg[u|1][k][j]);
        }
    }
}
void upd(int l,int r,int p,int v,char c){
    if (r-l == 1){
        s[l] = c;
        rep(i,0,4) rep(j,0,4) seg[v][i][j] = 0;
        if (s[l] == 'a'){
            rep(i,0,4)
                rep(j,i+1,4)
                    seg[v][i][j] = inf;
            seg[v][0][1] = 0;
            seg[v][0][0] = 1;
            return;
        }
        if (s[l] == 'b'){
            rep(i,0,4)
                rep(j,i+1,4)
                    seg[v][i][j] = inf;
            seg[v][1][2] = 0;
            seg[v][1][1] = 1;
            return;
        }
        rep(i,0,4)
            rep(j,i+1,4)
                seg[v][i][j] = inf;
        seg[v][2][3] = 0;
        seg[v][2][2] = 1;
        return;
    }
    int m = (l+r) >> 1,u = (v << 1);
    if (p < m) upd(l,m,p,u,c);
    else upd(m,r,p,u|1,c);
    rep(i,0,4){
        rep(j,i,4){
            seg[v][i][j] = inf;
            rep(k,i,j+1)
                seg[v][i][j] = min(seg[v][i][j],seg[u][i][k]+seg[u|1][k][j]);
        }
    }
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q >> s; 
    build(0,n,1);
    while (q--){
        int p;
        char c;
        cin >> p >> c;
        p--;
        upd(0,n,p,1,c);
        int ans = inf;
        rep(j,0,3) ans = min(ans,seg[1][0][j]);
        cout << ans << endl;
    }
}