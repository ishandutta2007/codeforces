#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
const int MAXA=5000;
const int MAXK=8192;
vector<int> loc[MAXA+5];
int dp[2][MAXK+5];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        loc[a].push_back(i);
    }
    for(int i=0;i<2;i++)
        for(int j=0;j<MAXK;j++)
            dp[i][j]=n+1;
    int now=0,la=1;
    dp[now][0]=0;
    for(int i=0;i<=MAXA;i++)
    {
        if(loc[i].empty())continue;
        swap(now,la);
        for(int j=0;j<MAXK;j++)
            dp[now][j]=dp[la][j];
        for(int j=0;j<MAXK;j++)
        {
            if(dp[la][j]<loc[i].front())
                dp[now][j^i]=min(dp[now][j^i],loc[i].front());
            else if(dp[la][j]<loc[i].back())
                dp[now][j^i]=min(dp[now][j^i],*lower_bound(loc[i].begin(),loc[i].end(),dp[la][j]));
        }
    }
    vector<int> res;
    for(int j=0;j<MAXK;j++)
        if(dp[now][j]<=n)res.push_back(j);
    printf("%d\n",(int)res.size());
    for(int i=0;i<(int)res.size();i++)
        printf("%d%c",res[i]," \n"[i==(int)res.size()-1]);
    return 0;
}