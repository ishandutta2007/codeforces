
#include<stdio.h>
#include<string.h>
using namespace std;
#define ll __int64
ll gcd(ll x,ll y)
{
    if(x%y==0)return y;
    else return gcd(y,x%y);
}
int a[500];
ll t[500];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        int flag2=0;
        for(int i=1;i<=n;i++)
        {
            int sum=0;
            int flag=0;
            int cnt=0;
            int now=i;
            while(1)
            {
                cnt++;
                now=a[now];
                if(now==i)
                {
                    flag=1;
                    break;
                }
                if(cnt>10000)break;
            }
            if(flag==0)
            {
                flag2=1;
                break;
            }
            t[i]=(ll)cnt;
            if(t[i]%2==0)t[i]=t[i]/2;
        }
        if(flag2==1)printf("-1\n");
        else
        {
            ll output=t[1];
            for(int i=2;i<=n;i++)
            {
                ll tmp=gcd(output,t[i]);
                output=output/tmp*t[i];
            }
            printf("%I64d\n",output);
        }
    }
}