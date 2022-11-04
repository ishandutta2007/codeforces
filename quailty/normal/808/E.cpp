#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=100005;
const int MAXM=300005;
ll dp[MAXM];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    vector<int> val[3];
    for(int i=1;i<=n;i++)
    {
        int w,c;
        scanf("%d%d",&w,&c);
        val[w-1].push_back(c);
    }
    for(int i=0;i<3;i++)
        sort(val[i].begin(),val[i].end(),greater<int>());
    if(val[0].size()&1)val[0].push_back(0);
    int cnt[2]={0,0};
    for(int i=2;i<=m;i+=2)
    {
        int add[2]={0,0};
        if(cnt[0]<(int)val[0].size())
            add[0]=val[0][cnt[0]]+val[0][cnt[0]+1];
        if(cnt[1]<(int)val[1].size())
            add[1]=val[1][cnt[1]];
        dp[i]=dp[i-2]+max(add[0],add[1]);
        if(add[0]>add[1])cnt[0]+=2;
        else cnt[1]+=1;
    }
    cnt[0]=1,cnt[1]=0;
    if(~val[0].size()&1)val[0].push_back(0);
    dp[1]=val[0][0];
    for(int i=3;i<=m;i+=2)
    {
        int add[2]={0,0};
        if(cnt[0]<(int)val[0].size())
            add[0]=val[0][cnt[0]]+val[0][cnt[0]+1];
        if(cnt[1]<(int)val[1].size())
            add[1]=val[1][cnt[1]];
        dp[i]=dp[i-2]+max(add[0],add[1]);
        if(add[0]>add[1])cnt[0]+=2;
        else cnt[1]+=1;
    }
    ll res=dp[m],now=0;
    for(int i=0;i<(int)val[2].size();i++)
    {
        now+=val[2][i],m-=3;
        if(m>=0)res=max(res,dp[m]+now);
    }
    return 0*printf("%lld",res);
}