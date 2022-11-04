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
    int n,l;
    scanf("%d%d",&n,&l);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int res=2*max(a[1],l-a[n]);
    for(int i=1;i<n;i++)
        res=max(res,a[i+1]-a[i]);
    printf("%.10f\n",res/2.0);
    return 0;
}