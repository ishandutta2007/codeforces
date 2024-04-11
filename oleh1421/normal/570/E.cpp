#include <bits/stdc++.h>
#define endl '\n'
const long long mod=1000000007;
typedef long long ll;
using namespace std;
const int N=603;
ll dp[2][N][N];
int a[N][N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            char c;cin>>c;
            a[i][j]=(c-'a');
        }
    }
    dp[0][1][n]=(a[1][1]==a[n][m]);
    int x=(n+m-2)/2;
    for (int d=1;d<=x;d++){
        for (int i=1;i<=n;i++){
            for (int j=i;j<=n;j++){
                int y1=d-i+2;
                int y2=n+m-j-d;
                dp[d%2][i][j]=0;
                if (y1<1 || y1>m) continue;
                if (y2<1 || y2>m) continue;
                if (y1>y2) continue;
                if (a[i][y1]!=a[j][y2]) continue;
                dp[d%2][i][j]=(dp[(d-1)%2][i][j]+dp[(d-1)%2][i][j+1]+dp[(d-1)%2][i-1][j]+dp[(d-1)%2][i-1][j+1])%mod;
            }
        }
    }
    ll sum=0ll;
    for (int d=x;d<=x;d++){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                int y1=d-i+2;
                int y2=n+m-j-d;
                if (y1<1 || y1>m) continue;
                if (y2<1 || y2>m) continue;
                if (abs(i-j)+abs(y1-y2)<=1) {
                    sum=(sum+dp[d%2][i][j])%mod;
                    //cout<<d<<" "<<i<<" "<<j<<" "<<dp[d%2][i][j]<<endl;
                }

            }
        }
    }
    /*for (int i=1;i<=n;i++)
        sum+=dp[x][i][i]+dp[x][i][i+1];*/
    cout<<sum<<endl;

    return 0;
}
/*
5 5
aaaaa
adaaa
aaaaa
aa#aa
aacaa
*/