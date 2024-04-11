#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int a[200005],b[200005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        a[i]+=i;
    }
    sort(a,a+n);
    for(int i=n-1;i>=0;i--)
    {
        b[i]=a[i]-i;
    }
    bool flag=1;
    if(b[0]<0)flag=0;
    for(int i=1;i<n;i++)
    {
        if(b[i]<b[i-1])flag=0;
    }
    if(!flag)printf(":(\n");
    else
    {
        for(int i=0;i<n;i++)
        {
            printf("%d ",b[i]);
        }
    }
    return 0;
}