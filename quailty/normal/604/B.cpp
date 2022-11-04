#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int a[100005];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    k=min(n,k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int res=0;
    for(int i=n;i>2*(n-k);i--)
        res=max(res,a[i]);
    for(int i=1;i<=n-k;i++)
        res=max(res,a[i]+a[2*(n-k)+1-i]);
    printf("%d\n",res);
    return 0;
}