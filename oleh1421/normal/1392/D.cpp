#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=200100;
const ll mod=998244353;
int dp[N][2][2];
int a[N];
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    for (int i=0;i<n;i++){
        a[i+1]=(s[i]=='R');
    }
    int res=n;

    for (int x=0;x<2;x++){
        for (int y=0;y<2;y++){
            for (int i=0;i<=n+1;i++){
                for (int j=0;j<2;j++){
                    for (int t=0;t<2;t++){
                        dp[i][j][t]=n+1;
                    }
                }
            }

            dp[2][a[2]][(a[2]==x)]=0;
            dp[2][a[2]^1][(a[2]!=x)]=1;
            for (int i=0;i<2;i++){
                if (i==x && i==y) dp[2][i][(i==x)]=n+1;
            }
            for (int i=2;i<n-1;i++){
                for (int j=0;j<2;j++){
                    for (int t=0;t<2;t++){
                        if (t+1<2) dp[i+1][j][t+1]=min(dp[i+1][j][t+1],dp[i][j][t]+(a[i+1]^j));
                        dp[i+1][j^1][0]=min(dp[i+1][j^1][0],dp[i][j][t]+(a[i+1]^j^1));
                    }
                }
            }
            for (int i=0;i<2;i++){
                for (int j=0;j<2;j++){
                    if (i==y && j) continue;
                    if (i==x && i==y) continue;
                    res=min(res,dp[n-1][i][j]+(a[1]!=x)+(a[n]!=y));
                }
            }
        }
    }
    cout<<res<<endl;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}