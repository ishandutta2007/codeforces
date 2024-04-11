#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
const int MAXK=512;
int a[MAXN],dp[MAXN][MAXK+5];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int j=0;j<MAXK;j++)
        dp[0][j]=(j>0)*MAXK;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<MAXK;j++)
            dp[i][j]=dp[i-1][j];
        for(int j=0;j<MAXK;j++)
            if(dp[i-1][j]<a[i])
                dp[i][j^a[i]]=min(dp[i][j^a[i]],a[i]);
    }
    vector<int> res;
    for(int j=0;j<MAXK;j++)
        if(dp[n][j]<MAXK)res.push_back(j);
    printf("%d\n",(int)res.size());
    for(int i=0;i<(int)res.size();i++)
        printf("%d%c",res[i]," \n"[i==(int)res.size()-1]);
    return 0;
}