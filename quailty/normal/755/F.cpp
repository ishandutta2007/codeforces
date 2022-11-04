#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<bitset>
using namespace std;
const int MAXN=1000005;
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    vector<int>p(MAXN),vis(MAXN);
    for(int i=1;i<=n;i++)
        scanf("%d",&p[i]);
    vector<int>cir;
    for(int i=1;i<=n;i++)
    {
        if(vis[i])continue;
        int t=i,len=0;
        while(!vis[t])
        {
            vis[t]=1;
            t=p[t];
            len++;
        }
        cir.push_back(len);
    }
    sort(cir.begin(),cir.end());
    vector<int>val;
    for(int i=0,j=0;i<(int)cir.size();i=j)
    {
        while(j<(int)cir.size() && cir[i]==cir[j])j++;
        for(int k=0,t=j-i;t;k++)
        {
            if(t>(1<<k))val.push_back(cir[i]<<k);
            else val.push_back(cir[i]*t);
            t=max(0,t-(1<<k));
        }
    }
    bitset<MAXN>dp[2];
    int now=0,la=1;
    dp[now].reset();
    dp[now][0]=1;
    for(int i=0;i<(int)val.size();i++)
    {
        swap(now,la);
        dp[now]=dp[la]|(dp[la]<<val[i]);
    }
    printf("%d ",k+1-dp[now][k]);
    int res=0;
    for(int i=0;i<(int)cir.size() && k;i++)
        while(cir[i]>1 && k)cir[i]-=2,res+=2,k--;
    for(int i=0;i<(int)cir.size() && k;i++)
        while(cir[i]>0 && k)cir[i]-=1,res+=1,k--;
    printf("%d\n",res);
    return 0;
}