#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=15;
int n,a,b,h[MAXN];
int ans=150,c[MAXN],res[MAXN],buf[MAXN];
void dfs(int now)
{
    if(now>n-1)
    {
        if(h[now-1]<0)
        {
            int sum=0;
            for(int i=2;i<=n-1;i++)sum+=c[i];
            if(sum<ans)
            {
                ans=sum;
                for(int i=2;i<=n-1;i++)res[i]=c[i];
            }
        }
        return;
    }
    for(int i=8;i>=0 && i*b>h[now-1];i--)
    {
        c[now]=i;
        h[now]-=i*a;
        h[now+1]-=i*b;
        dfs(now+1);
        h[now]+=i*a;
        h[now+1]+=i*b;
    }
}
int main()
{
    scanf("%d%d%d",&n,&a,&b);
    for(int i=1;i<=n;i++)
        scanf("%d",&h[i]);
    buf[2]=max(buf[2],h[1]/b+1);
    buf[n-1]=max(buf[n-1],h[n]/b+1);
    h[1]-=b*buf[2],h[2]-=a*buf[2],h[3]-=b*buf[2];
    if(n>3)h[n-2]-=b*buf[n-1],h[n-1]-=a*buf[n-1],h[n]-=b*buf[n-1];
    dfs(2);
    printf("%d\n",ans+buf[2]+(n>3)*buf[n-1]);
    for(int i=2;i<=n-1;i++)
        for(int j=0;j<res[i]+buf[i];j++)
            printf("%d ",i);
    return 0;
}