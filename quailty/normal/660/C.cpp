#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int a[300005];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        a[i]+=a[i-1];
    int l=0,r=n,st=1;
    while(l<r)
    {
        int m=(l+r+1)>>1;
        bool isok=0;
        for(int i=0;i+m<=n;i++)
            if(a[i+m]-a[i]>=m-k)
            {
                st=i+1;
                isok=1;
            }
        if(isok)l=m;
        else r=m-1;
    }
    printf("%d\n",l);
    for(int i=1;i<st;i++)
        printf("%d ",a[i]-a[i-1]);
    for(int i=st;i<st+l;i++)
        printf("1 ");
    for(int i=st+l;i<=n;i++)
        printf("%d ",a[i]-a[i-1]);
    return 0;
}