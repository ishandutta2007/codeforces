#include <bits/stdc++.h>
#pragma GCC optimize("O2")
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
const long long int N = 2e5+10,mod = 1e9+7,inf = 1e9,sq = 500;
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
int seg[4*N][5][5];
string s;
int dp[100][5];
vector<int> ve;
void build(int l,int r,int v){
    if (r-l == 1){
        if(s[l] == '2'){
            seg[v][0][1] = 0;
            seg[v][0][0] = 1;
            rep(i,1,5) seg[v][i][i] = 0;
            return;
        }
        if(s[l] == '0'){
            seg[v][0][0] = 0;
            seg[v][1][1] = 1;
            rep(i,2,5) seg[v][i][i] = 0;
            seg[v][1][2] = 0;
            return;
        }
        if (s[l] == '1'){
            seg[v][0][0] = 0;
            seg[v][1][1] = 0;
            seg[v][2][2] = 1;
            seg[v][2][3] = 0;
            rep(i,3,5) seg[v][i][i] = 0;
            return;
        }
        if (s[l] == '6'){
            rep(i,0,3) seg[v][i][i] = 0;
            seg[v][3][3] = 1;
            seg[v][4][4] = 1;
            return;
        }
        if (s[l] == '7'){
            rep(i,0,3) seg[v][i][i] = 0;
            seg[v][3][3] = 1;
            seg[v][3][4] = 0;
            seg[v][4][4] = 0;
            return;
        }
        rep(i,0,5) seg[v][i][i] = 0;
        return;
    }
    int m = (l+r) >> 1,u = (v << 1);
    build(l,m,u);
    build(m,r,u|1);
    rep(i,0,5)
        rep(j,i,5)
            rep(k,i,j+1)
                seg[v][i][j] = min(seg[v][i][j],seg[u][i][k]+seg[u|1][k][j]);
}
void que(int l,int r,int s,int e,int v = 1){
    if (l >= s && e >= r){
        ve.pb(v);
        return;
    }
    if (l >= e || s >= r) return;
    int m = (l+r) >> 1;
    int u = (v << 1);
    que(l,m,s,e,u);
    que(m,r,s,e,u|1);
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(seg,63,sizeof seg);
    int n,q;
    cin >> n >> q >> s;
    build(0,n,1);
    while(q--){
        int l,r;
        cin >> l >> r;
        ve.reserve(100);
        l--;
        que(0,n,l,r);
        int sz = ve.size();
        rep(i,0,5) dp[0][i] = seg[ve[0]][0][i];
        rep(i,1,sz){
            rep(j,0,5){
                dp[i][j] = inf;
                rep(k,0,j+1)
                    dp[i][j] = min(dp[i][j],dp[i-1][k]+seg[ve[i]][k][j]);
            }
        }
        if (dp[sz-1][4] < inf) cout << dp[sz-1][4] << endl;
        else cout << -1 << endl;
        ve.clear();
    }
}