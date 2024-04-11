#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
typedef long long ll;
using namespace std;
int c[200001];
int dp[511][511];
const int mod=998244353ll;
int solve(int l,int r){
    if (l>r) return 1ll;
    if (l==r) return 1ll;
    if (dp[l][r]!=-1) return dp[l][r];
    int minx=1000001;
    for (int i=l;i<=r;i++) minx=min(minx,c[i]);
    int m=0;
    for (int i=l;i<=r;i++){
        if (minx==c[i]){
            m=i;
            break;
        }
    }
    int resl=0ll;
    for (int i=l;i<=m;i++){
        resl+=(solve(l,i-1)*solve(i,m-1))%mod;
        resl%=mod;
    }
    int resr=0ll;
    for (int i=m;i<=r;i++){
        resr+=(solve(m+1,i)*solve(i+1,r))%mod;
        resr%=mod;
    }
    return dp[l][r]=(resl*resr)%mod;
}
int32_t main() {
    int n;cin>>n>>n;
    for (int i=1;i<=n;i++) cin>>c[i];
    for (int l=1;l<=n;l++) for (int r=1;r<=n;r++) dp[l][r]=-1;
    cout<<solve(1,n);

    return 0;
}
//20000000000000