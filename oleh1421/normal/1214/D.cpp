#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
///#define int long long
typedef long long ll;
using namespace std;
const long long mod=489458341ll;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;cin>>n>>m;
    vector<vector<char> >v;
    vector<vector<ll> >dp;
    vector<vector<ll> >dp1;
    v.resize(n);
    dp.resize(n);
    dp1.resize(n);
    for (int i=0;i<n;i++){
        v[i].resize(m);
        dp[i].resize(m);
        dp1[i].resize(m);
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            char c;cin>>c;
            v[i][j]=(c=='#');
        }
    }
    int res=2;
    dp[0][0]=1;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (v[i][j]) dp[i][j]=0ll;
            else {
                if (i+1<n) dp[i+1][j]=(dp[i+1][j]+dp[i][j])%mod;
                if (j+1<m) dp[i][j+1]=(dp[i][j+1]+dp[i][j])%mod;
            }
        }
    }
    dp1[n-1][m-1]=1;
    for (int i=n-1;i>=0;i--){
        for (int j=m-1;j>=0;j--){
            if (v[i][j]) dp1[i][j]=0ll;
            else {
                if (i>0) dp1[i-1][j]=(dp1[i-1][j]+dp1[i][j])%mod;
                if (j>0) dp1[i][j-1]=(dp1[i][j-1]+dp1[i][j])%mod;
            }
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (i==0 && j==0) continue;
            if (i==n-1 && j==m-1) continue;
            if (v[i][j]) continue;
            if ((dp[i][j]*dp1[i][j])%mod==dp[n-1][m-1]) res=1;
        }
    }
    if (dp1[0][0]==0) res=0;
    cout<<res;
    return 0;
}