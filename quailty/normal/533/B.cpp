#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
typedef long long ll;
using namespace std;
ll a[200005],dp[200005][2];
vector<int>e[200005];
void dfs(int from)
{
    ll t0=0,t1=-1;
    for(int i=0;i<e[from].size();i++)
    {
        int to=e[from][i];
        dfs(to);
        ll tt0=t0,tt1=t1;
        if(dp[to][0]!=-1)
        {
            if(tt0!=-1)t0+=dp[to][0];
            if(tt1!=-1)t1+=dp[to][0];
        }
        if(dp[to][1]!=-1)
        {
            if(tt0!=-1)t1=max(t1,tt0+dp[to][1]);
            if(tt1!=-1)t0=max(t0,tt1+dp[to][1]);
        }
    }
    dp[from][0]=t0;
    dp[from][1]=max(t1,t0+a[from]);
}
int main()
{
    int n;
    memset(dp,-1,sizeof(dp));
    scanf("%d",&n);
    int p,root;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%I64d",&p,&a[i]);
        if(p==-1)
        {
            root=i;
        }
        else
        {
            e[p].push_back(i);
        }
    }
    dfs(root);
    printf("%I64d\n",max(dp[root][0],dp[root][1]));
    return 0;
}