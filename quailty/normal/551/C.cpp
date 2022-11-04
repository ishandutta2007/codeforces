#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a[100005],sum;
struct pile
{
    ll loc,cnt;
}b[100005],c[100005];
int tot=0;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    ll sum=0,ma=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%I64d",&a[i]);
        sum+=a[i];
        if(a[i])
        {
            ma=i;
            b[++tot].loc=i;
            b[tot].cnt=a[i];
        }
    }
    ll l=ma,r=sum+ma;
    while(l<r)
    {
        ll t=(l+r)>>1;
        int now=1;
        for(int i=1;i<=tot;i++)c[i]=b[i];
        for(int i=1;i<=m;i++)
        {
            ll la=t-c[now-1].loc;
            while(la>0 && now<=tot)
            {
                la+=c[now-1].loc;
                la-=c[now].loc;
                ll p=min(la,c[now].cnt);
                c[now].cnt-=p;
                la-=p;
                if(!c[now].cnt)now++;
            }
        }
        if(now>tot)r=t;
        else l=t+1;
    }
    printf("%I64d\n",l);
    return 0;
}