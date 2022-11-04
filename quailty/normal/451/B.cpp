#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int a[100005],ta[100005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    memcpy(ta,a,sizeof(a));
    sort(ta+1,ta+n+1);
    for(int i=1;i<=n;i++)
        a[i]=lower_bound(ta+1,ta+n+1,a[i])-ta;
    int l=0,r=0;
    for(int i=1;i<=n;i++)
        if(a[i]!=i)r=i;
    for(int i=n;i>=1;i--)
        if(a[i]!=i)l=i;
    if(!l)l=r=1;
    for(int i=l;i<=r;i++)
        if(a[i]!=l+r-i)return 0*printf("no");
    printf("yes\n%d %d\n",l,r);
    return 0;
}