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
    int n,mi=1000000000,mx=0,res=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        mi=min(mi,a[i]);
        mx=max(mx,a[i]);
    }
    for(int i=1;i<=n;i++)
        res+=(a[i]>mi && a[i]<mx);
    return 0*printf("%d",res);
}