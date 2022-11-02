#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse4")
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
constexpr int N = 2e5+20,mod = 1e9+7 ,inf = 1e9+10;
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
int seg[N*4][2],lz[N*4][2];
int dp[N][2];
void build(int l,int r,int v = 1){
    seg[v][0] = seg[v][1] = inf;
    lz[v][0] = lz[v][1] = 0;
    if (r-l == 1) return;
    int m = (l+r) >> 1,u = (v << 1);
    build(l,m,u);
    build(m,r,u|1);
}
void pass(int v){
    int u = (v << 1);
    rep(j,0,2){
        lz[u][j] += lz[v][j];
        lz[u|1][j] += lz[v][j];
        seg[u][j] += lz[v][j];
        seg[u|1][j] += lz[v][j];
        lz[v][j] = 0;
    }
}
void upd(int l,int r,int p,bool f,int x,int v = 1){
    if (r-l == 1){
        seg[v][f] = x;
        return;
    }
    int m = (l+r) >> 1,u = (v << 1);
    pass(v);
    if (p < m) upd(l,m,p,f,x,u);
    else upd(m,r,p,f,x,u|1);
    seg[v][0] = min(seg[u][0],seg[u|1][0]);
    seg[v][1] = min(seg[u][1],seg[u|1][1]);
}
inline void solve(){
    int n;
    cin >> n;
    string s[2];
    cin >> s[0] >> s[1];
    build(0,n+1,1);
    int lst = -1;
//    upd(0,n+1,0,0,0);
  //  upd(0,n+1,0,1,0);
    rep(i,0,n){
        if (lst != -1){
            lz[1][0]++;
            lz[1][1]++;
            seg[1][0]++;
            seg[1][1]++;
        }
        if (s[0][i] == '*' && s[1][i] == '*'){
            dp[i][0] = min(seg[1][0],seg[1][1])+1;
            dp[i][1] = min(seg[1][1],seg[1][0])+1;
        }
        if (s[0][i] == '*' && s[1][i] == '.'){
            dp[i][0] = min(seg[1][0],seg[1][1]+1);
            dp[i][1] = min(seg[1][1],seg[1][0])+1;
        }
        if (s[0][i] == '.' && s[1][i] == '*'){
            dp[i][0] = min(seg[1][0],seg[1][1])+1;
            dp[i][1] = min(seg[1][1],seg[1][0]+1);
        }
        if (s[0][i] == '.' && s[1][i] == '.'){
            dp[i][0] = min(seg[1][0],seg[1][1]+1);
            dp[i][1] = min(seg[1][1],seg[1][0]+1);
        }
        if (lst == -1){
            if (s[1][i] == '*') dp[i][0] = 1;
            else dp[i][0] = 0;
            if (s[0][i] == '*') dp[i][1] = 1;
            else dp[i][1] = 0;
        }
        if(s[1][i] == '*'){
            lz[1][0]++;
            seg[1][0]++;
            lst = i;
        }
        if (s[0][i] == '*'){
            lz[1][1]++;
            seg[1][1]++;
            lst = i;
        }
        upd(0,n+1,i+1,0,dp[i][0]);
        upd(0,n+1,i+1,1,dp[i][1]);
    }
    cout << min(dp[lst][0],dp[lst][1]) << endl;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        solve();
    }
}