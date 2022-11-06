#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=2000005;
ll cnt[MAXN],sum[MAXN];
int main()
{
    int n,x,y;
    scanf("%d%d%d",&n,&x,&y);
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        cnt[a]+=1;
        sum[a]+=a;
    }
    for(int i=1;i<MAXN;i++)
    {
        cnt[i]+=cnt[i-1];
        sum[i]+=sum[i-1];
    }
    ll res=(1LL<<60)-1;
    int lim=(x+y-1)/y;
    for(int d=2;d<=1000000;d++)
    {
        ll now=0;
        for(int i=1;i<=1000000;i+=d)
        {
            int t=min(lim,d);
            now+=x*(cnt[i+d-t-1]-cnt[i-1]);
            now+=y*(cnt[i+d-1]-cnt[i+d-t-1])*(i+d-1);
            now-=y*(sum[i+d-1]-sum[i+d-t-1]);
        }
        res=min(res,now);
    }
    printf("%lld\n",res);
    return 0;
}