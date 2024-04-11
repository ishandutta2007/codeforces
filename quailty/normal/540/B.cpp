#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int a[1005];
int main()
{
    int n,k,p,x,y;
    scanf("%d%d%d%d%d",&n,&k,&p,&x,&y);
    int cnt=0,sum=0;
    for(int i=1;i<=k;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
        if(a[i]<y)cnt++;
    }
    if(cnt>n/2)
    {
        printf("-1\n");
    }
    else
    {
        int t=min(n/2-cnt,n-k);
        int s=n-k-t;
        if(sum+t+s*y>x)
        {
            printf("-1\n");
        }
        else
        {
            for(int i=1;i<=t;i++)
            {
                printf("1 ");
            }
            for(int i=1;i<=s;i++)
            {
                printf("%d ",y);
            }
        }
    }
    return 0;
}