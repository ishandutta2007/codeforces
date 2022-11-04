#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
int p[MAXN];
pair<int,int>dp[MAXN];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&p[i]);
    int sz=sqrt(n)+0.5;
    for(int i=0;i<=(n-1)/sz;i++)
    {
        int r=i*sz+min(sz,n-i*sz);
        for(int j=r;j>i*sz;j--)
        {
            if(j+p[j]>r)dp[j]=make_pair(j,1);
            else dp[j]=make_pair(dp[j+p[j]].first,dp[j+p[j]].second+1);
        }
    }
    while(m--)
    {
        int ty,a,b;
        scanf("%d",&ty);
        if(ty==0)
        {
            scanf("%d%d",&a,&b);
            p[a]=b;
            int i=(a-1)/sz,r=i*sz+min(sz,n-i*sz);
            for(int j=r;j>i*sz;j--)
            {
                if(j+p[j]>r)dp[j]=make_pair(j,1);
                else dp[j]=make_pair(dp[j+p[j]].first,dp[j+p[j]].second+1);
            }
        }
        else
        {
            scanf("%d",&a);
            int la=0,now=a,res=0;
            while(now<=n)
            {
                res+=dp[now].second;
                la=dp[now].first;
                now=la+p[la];
            }
            printf("%d %d\n",la,res);
        }
    }
    return 0;
}