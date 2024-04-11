#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int MAXN=100005;
int a[MAXN];
ll dp[2][MAXN];
struct seg
{
    int l,r,tl,tr;
};
int cnt[MAXN],cl,cr;
ll now;
void trans(int n)
{
    memset(cnt,0,sizeof(cnt));
    cl=1,cr=0;
    now=0;
    queue<seg> q;
    q.push(seg{1,n,1,n});
    while(!q.empty())
    {
        seg u=q.front();
        q.pop();
        int l=u.l,r=u.r,tl=u.tl,tr=u.tr;
//        printf("%d %d %d %d\n",l,r,tl,tr);
        int m=(l+r)/2,tm=tl;
        ll &res=dp[1][m];
        while(cr<m)cr++,now+=cnt[a[cr]],cnt[a[cr]]++;
        while(cl>tl)cl--,now+=cnt[a[cl]],cnt[a[cl]]++;
        while(cr>m)cnt[a[cr]]--,now-=cnt[a[cr]],cr--;
        while(cl<tl)cnt[a[cl]]--,now-=cnt[a[cl]],cl++;
        for(int i=tl;i<=tr && i<=m;i++)
        {
            while(cl<i)cnt[a[cl]]--,now-=cnt[a[cl]],cl++;
            if(res>now+dp[0][i-1])
            {
                res=now+dp[0][i-1];
                tm=i;
            }
        }
        if(l<m)q.push(seg{l,m-1,tl,tm});
        if(r>m)q.push(seg{m+1,r,tm,tr});
    }
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    memset(dp,0x3f,sizeof(dp));
    dp[1][0]=0;
    for(int i=1;i<=k;i++)
    {
        memcpy(dp[0],dp[1],sizeof(dp[1]));
        memset(dp[1],0x3f,sizeof(dp[1]));
        trans(n);
//        for(int i=1;i<=n;i++)
//            printf("%lld ",dp[1][i]);
//        printf("\n");
    }
    printf("%lld\n",dp[1][n]);
    return 0;
}