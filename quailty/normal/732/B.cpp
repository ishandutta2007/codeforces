#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int a[505];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int res=0;
    for(int i=2;i<=n;i++)
    {
        int t=k-a[i]-a[i-1];
        if(t>0)res+=t,a[i]+=t;
    }
    printf("%d\n",res);
    for(int i=1;i<=n;i++)
        printf("%d ",a[i]);
    return 0;
}