#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll cnt[10000005];
int p[10000005],tot;
bool np[10000005];
void work()
{
    for(int i=1;i<=10000000;i++)
        cnt[i]+=cnt[i-1];
    for(int i=1;i<=10000000;i++)
        for(int j=2*i;j<=10000000;j+=i)
            cnt[i]+=cnt[j];
    for(int i=1;i<=tot;i++)
        for(ll now=1LL*p[i]*p[i];now<=10000000;now*=p[i])
            cnt[p[i]]+=cnt[now];
}
void build()
{
    for(int i=2;i<=10000000;i++)
        if(!np[i])
        {
            p[++tot]=i;
            for(int j=2*i;j<=10000000;j+=i)
                np[j]=1;
        }
}
ll get(ll n,int p)
{
    ll res=0;
    while(n)
    {
        n/=p;
        res+=n;
    }
    return res;
}
int main()
{
    build();
    int k;
    scanf("%d",&k);
    ll sum=0;
    for(int i=1;i<=k;i++)
    {
        int a;
        scanf("%d",&a);
        sum+=a;
        cnt[1]++;
        cnt[a+1]--;
    }
    work();
    ll ans=1;
    for(int i=1;i<=tot;i++)
    {
        ll l=ans,r=sum;
        while(l<r)
        {
            ll m=(l+r)>>1;
            if(get(m,p[i])<cnt[p[i]])l=m+1;
            else r=m;
        }
        ans=max(ans,l);
    }
    printf("%I64d\n",ans);
    return 0;
}