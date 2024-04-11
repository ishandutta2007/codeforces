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
typedef pair<int,int> pll;
const long long int N = 1e2+20,mod = 1e9+7,inf = 1e9,sq = 4e7;
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
int dp[N][N][N][2];
int n,V,K,A;
string s;
vector<int> ind[3];
void solve(int v,int k,int a,bool f){
    if (v == V && k == K && a == A){
        dp[v][k][a][f] = 0;
        return;
    }
    if (dp[v][k][a][f] != -1) return;
    dp[v][k][a][f] = inf;
    if (v < V){
        int b = 0;
        rep(i,k,K){
            if (ind[1][i] > ind[0][v]) break;
            b++;
        }
        rep(i,a,A){
            if (ind[2][i] > ind[0][v]) break;
            b++;
        }
        solve(v+1,k,a,1);
        dp[v][k][a][f] = min(dp[v][k][a][f],dp[v+1][k][a][1]+b);
    }
    if (!f && k < K){
        int b = 0;
        rep(i,v,V){
            if (ind[0][i] > ind[1][k]) break;
            b++;
        }
        rep(i,a,A){
            if (ind[2][i] > ind[1][k]) break;
            b++;
        }
        solve(v,k+1,a,0);
        dp[v][k][a][f] = min(dp[v][k][a][f],dp[v][k+1][a][0]+b);
    }
    if (a < A){
        int b = 0;
        rep(i,k,K){
            if (ind[1][i] > ind[2][a]) break;
            b++;
        }
        rep(i,v,V){
            if (ind[0][i] > ind[2][a]) break;
            b++;
        }
        solve(v,k,a+1,0);
        dp[v][k][a][f] = min(dp[v][k][a][f],dp[v][k][a+1][0]+b);
    }
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    memset(dp,-1,sizeof dp);
    cin >> n >> s;
    rep(i,0,n){
        if (s[i] == 'V'){
            V++;
            ind[0].pb(i);
        }
        else if (s[i] == 'K'){
            K++;
            ind[1].pb(i);
        }
        else{
            s[i] = 'A';
            A++;
            ind[2].pb(i);
        }
    }
    solve(0,0,0,0);
    cout << dp[0][0][0][0];
    return 0;
}