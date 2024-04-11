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
typedef pair<ll,ll> pll;
typedef pair<long double,long double> pld;
const long long int N = 4e3+10,mod = 1e9+7,inf = 1e9,sq = 500;
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
int u[N][N];
int dp[N][1000];
int pre[N][N];
int x;
void f(int s,int e,int l,int r){
    if (r <= l || e <= s) return;
    int m = (s+e) >> 1;
    int p = -1;
    int R = max(r,m+1);
    repr(i,R-1,l){
        if (pre[m][i+1] >= dp[m][x]) break;
        if (dp[i][x-1]+pre[m][i+1] < dp[m][x]){
            dp[m][x] = dp[i][x-1]+pre[m][i+1];
            p = i;
        }
    }
    f(s,m,l,p+1);
    f(m+1,e,p,r);
}
int main(){
  //  ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(dp,63,sizeof dp);
    int n,k;
    scanf("%d %d", &n , &k);
    getchar();
    rep(i,1,n+1){
        rep(j,1,n+1){
            u[i][j] = getchar()-'0';
            getchar();
        }
        repr(j,i-1,1){
            pre[i][j] = pre[i][j+1]+u[i][j];
            pre[i][j+1] += pre[i-1][j+1];
        }
        pre[i][1] += pre[i-1][1];
        dp[i][1] = pre[i][1];
    }
    for(x = 2; x <= k; x++) f(1,n+1,0,n+1);
    cout << dp[n][k];
}