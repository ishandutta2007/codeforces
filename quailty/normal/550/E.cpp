#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n,a[1000005];
void work()
{
    if(a[n]==1)
    {
        printf("NO\n");
        return;
    }
    if(a[n-1]==1)
    {
        printf("YES\n");
        for(int i=1;i<=n-3;i++)
        {
            printf("%d->",a[i]);
        }
        printf("(%d->1)",a[n-2]);
        printf("->0\n");
        return;
    }
    bool isok=0;
    int loc=0;
    for(int i=1;i<=n-2;i++)
    {
        if(a[i]==0)
        {
            isok=1;
            loc=i;
        }
    }
    if(!isok)
    {
        printf("NO\n");
        return;
    }
    printf("YES\n");
    for(int i=1;i<loc;i++)
    {
        printf("%d->",a[i]);
    }
    if(loc==n-2)
    {
        printf("(%d->%d)->%d",a[loc],a[loc+1],a[loc+2]);
    }
    else
    {
        printf("(%d->(",a[loc]);
        for(int i=loc+1;i<n-2;i++)
        {
            printf("%d->",a[i]);
        }
        printf("%d->%d))->%d",a[n-2],a[n-1],a[n]);
    }
    printf("\n");
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    if(n==1)
    {
        if(a[n]==1)printf("NO\n");
        else
        {
            printf("YES\n0\n");
        }
    }
    else if(n==2)
    {
        if(a[n]==1)printf("NO\n");
        else
        {
            if(a[n-1]==0)printf("NO\n");
            else printf("YES\n1->0\n");
        }
    }
    else work();
    return 0;
}