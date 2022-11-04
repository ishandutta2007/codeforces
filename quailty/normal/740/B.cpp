#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int a[105];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int res=0;
    for(int i=1;i<=m;i++)
    {
        int l,r,now=0;
        scanf("%d%d",&l,&r);
        for(int j=l;j<=r;j++)
            now+=a[j];
        res+=max(0,now);
    }
    printf("%d\n",res);
    return 0;
}