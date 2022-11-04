#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=100005;
const ll INF=(1LL<<62)-1;
string str[MAXN][2];
ll c[MAXN],dp[MAXN][2];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>c[i];
    for(int i=1;i<=n;i++)
    {
        cin>>str[i][0];
        str[i][1]=str[i][0];
        reverse(str[i][1].begin(),str[i][1].end());
    }
    for(int i=0;i<=n;i++)
        dp[i][0]=dp[i][1]=INF;
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
        for(int j=0;j<2;j++)
            for(int k=0;k<2;k++)
                if(str[i][j]>=str[i-1][k])
                    dp[i][j]=min(dp[i][j],dp[i-1][k]+j*c[i]);
    ll res=min(dp[n][0],dp[n][1]);
    cout<<(res<INF ? res : -1)<<endl;
    return 0;
}