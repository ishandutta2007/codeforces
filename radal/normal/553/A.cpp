#include <bits/stdc++.h>
#define ll long long int
#define rep(i,l,r) for(ll i=l; i<r; i++)
#define X first
#define Y second
using namespace std;
const ll N=1e3+20,mod=1e9+7;
ll a[N],s[N];
ll dp[N],C[N][N];
int main(){
    ios ::sync_with_stdio(false); 
    cin.tie(0);
    ll n,k;
    cin >> n;
    rep (i,0,n){
        cin >> a[i];
    }
    rep (i,0,N){
        C[i][0] = 1;
        C[i][N] = 1;
    }
    rep (i,1,N){
        rep (j,1,i+1){
            C[i][j] = (C[i-1][j]+C[i-1][j-1])%mod;
        }
    }
    s[0] = a[0];
    rep (i,1,n){
        s[i] = s[i-1] + a[i];
    }
    dp[0] = 1;
    rep (i,1,n){
        dp[i] =dp[i-1]*C[a[i]+s[i-1]-1][s[i-1]];
        dp[i] %= mod;
       // cout << i << "   " << dp[i] << endl;
    }
    cout << dp[n-1];
}