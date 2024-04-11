#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=5005;
pair<pair<int,int>,int>a[MAXN];
int dp[MAXN],pre[MAXN];
void output(int n)
{
    if(!n)return;
    output(pre[n]);
    printf("%d ",a[n].second);
}
int main()
{
    int n,w,h;
    scanf("%d%d%d",&n,&w,&h);
    int tot=0;
    a[tot++]=make_pair(make_pair(w,h),tot);
    for(int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(x>w && y>h)
            a[tot++]=make_pair(make_pair(x,y),i);
    }
    sort(a,a+tot);
    for(int i=0;i<tot;i++)
        for(int j=0;j<i;j++)
            if(a[j].first.first<a[i].first.first
               && a[j].first.second<a[i].first.second
               && dp[i]<dp[j]+1)
            {
                dp[i]=dp[j]+1;
                pre[i]=j;
            }
    int loc=0;
    for(int i=0;i<tot;i++)
        if(dp[loc]<dp[i])loc=i;
    printf("%d\n",dp[loc]);
    output(loc);
    return 0;
}