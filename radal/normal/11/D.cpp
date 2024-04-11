#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define mp make_pair
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const long long int N=20,mod = 1e9+7,inf=2e18,dlt = 12250,maxm = 524288;
ll dp[N][maxm];
bool e[N][N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin >> n >> m;
    rep(i,0,m){
        int u,v;
        cin >> u >> v;
        u--;
        v--;
        e[u][v] = e[v][u] = 1;
    }
    int p = (1 << n); 
    ll ans = 0;
    rep(i,0,n) dp[i][(1 << i)] = 1;
    rep(i,1,p){
        if (__builtin_popcount(i) == 1) continue;
        int l = 0;
        rep(j,0,n){
            if (i&(1 << j)){
                l = j;
                break;
            }
        }
        if (__builtin_popcount(i) == 2){
            rep(j,0,n){
                dp[j][i] = (e[l][j] && (i&(1 << j)));
            }
            continue;
        }
        rep(j,l+1,n){
            if (i&(1 << j)){
                rep(k,l+1,n){
                    if (e[j][k] && (i&(1 << k))){
                        dp[j][i] += dp[k][i-(1<<j)];
                    }
                }
                if (e[j][l]){
                    ans += dp[j][i];
                }
            }
        }
    }
    cout << ans/2;

}