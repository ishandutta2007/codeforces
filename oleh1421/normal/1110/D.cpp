#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
//#define int long long
typedef long long ll;
using namespace std;
int dp[1000001][3][3];
int a[1000011];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++){
        int x;cin>>x;
        a[x]++;
    }
    dp[2][0][0]=0;
    for (int i=2;i<m;i++){
        for (int j=0;j<=2;j++){
            for (int t=0;t<=2;t++){
                for (int g=0;g<=2 && g<=a[i+1] && g<=a[i]-t && g<=a[i-1]-j-t;g++){
                    dp[i+1][t][g]=max(dp[i+1][t][g],dp[i][j][t]+g+(a[i-1]-j-t-g)/3);
                }
            }
        }
    }
    int res=0;
    for(int i=0;i<=2;i++){
        for (int j=0;j<=2;j++){
            res=max(res,dp[m][i][j]+(a[m-1]-i-j)/3+(a[m]-j)/3);
        }
    }
    cout<<res;
    return 0;
}