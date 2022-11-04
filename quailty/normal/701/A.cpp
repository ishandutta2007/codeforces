#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int a[105],usd[105];
int main()
{
    int n,sum=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    sum/=n/2;
    for(int i=1;i<=n;i++)
    {
        if(usd[i])continue;
        usd[i]=1;
        for(int j=i+1;j<=n;j++)
            if(!usd[j] && a[i]+a[j]==sum)
            {
                printf("%d %d\n",i,j);
                usd[j]=1;
                break;
            }
    }
    return 0;
}