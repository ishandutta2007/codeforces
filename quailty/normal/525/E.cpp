#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
int T[25],a[35];
ll fac[25];
map<ll,ll>cnt[35];
void build()
{
    T[0]=1;
    for(int i=1;i<=15;i++)T[i]=3*T[i-1];
    fac[0]=1;
    for(int i=1;i<=18;i++)fac[i]=i*fac[i-1];
}
int main()
{
    build();
    int n,k;
    ll S;
    scanf("%d%d%I64d",&n,&k,&S);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    for(int i=0;i<T[n/2];i++)
    {
        int mask=i,tot=0;
        ll now=0;
        bool isok=1;
        for(int j=0;j<n/2;j++)
        {
            if(mask%3==1)now+=a[j];
            else if(mask%3==2)
            {
                if(a[j]>18)
                {
                    isok=0;
                    break;
                }
                now+=fac[a[j]];
                tot++;
            }
            mask/=3;
        }
        if(isok)cnt[tot][now]++;
    }
    ll ans=0;
    for(int i=0;i<T[n-n/2];i++)
    {
        int mask=i,tot=0;
        ll now=0;
        bool isok=1;
        for(int j=0;j<n-n/2;j++)
        {
            if(mask%3==1)now+=a[j+n/2];
            else if(mask%3==2)
            {
                if(a[j+n/2]>18)
                {
                    isok=0;
                    break;
                }
                now+=fac[a[j+n/2]];
                tot++;
            }
            mask/=3;

        }
        if(isok)
            for(int p=0;p<=k-tot;p++)
                if(cnt[p].find(S-now)!=cnt[p].end())
                    ans+=cnt[p][S-now];
    }
    printf("%I64d\n",ans);
    return 0;
}