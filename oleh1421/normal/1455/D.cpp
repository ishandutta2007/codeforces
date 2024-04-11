#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=510;
int a[N];
int dp[2][N][N];
void solve(){
    int n,x;cin>>n>>x;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=0;i<2;i++){
        for (int j=0;j<N;j++){
            for (int t=0;t<N;t++){
                dp[i][j][t]=N;
            }
        }
    }
    dp[0][0][x]=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<N;j++){
            for (int t=0;t<N;t++){
                dp[(i+1)%2][j][t]=N;
            }
        }
        for (int j=0;j<N;j++){
            for (int t=0;t<N;t++){
                if (j<=a[i+1]) dp[(i+1)%2][a[i+1]][t]=min(dp[(i+1)%2][a[i+1]][t],dp[i%2][j][t]);
                if (t<a[i+1] && j<=t) dp[(i+1)%2][t][a[i+1]]=min(dp[(i+1)%2][t][a[i+1]],dp[i%2][j][t]+1);
            }
        }
    }
    int res=N;
    for (int j=0;j<N;j++){
        for (int t=0;t<N;t++){
            res=min(res,dp[n%2][j][t]);
        }
    }
    if (res==N) res=-1;
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
//2 3 4 5
//2 3 4 5 6 7 8 9 10 11 12 14
//x y