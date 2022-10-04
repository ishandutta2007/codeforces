#include<cstdio>
#include<cmath>
#define LL long long
LL a[0xffff];
int main()
{
    LL n,k,t=0;
    scanf("%I64d %I64d",&n,&k);
    for(LL i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            t++;
            if(t==k)
            {
                printf("%lld",i); return 0;
            }
            a[t]=n/i;
        }
    }
    for(LL j=t;j>=1;j--)
    {
        if(a[j]*a[j]==n) continue;
        t++;
        if(t==k){
            printf("%lld",a[j]); return 0;
        }
    }
    printf("-1");
    return 0;
}