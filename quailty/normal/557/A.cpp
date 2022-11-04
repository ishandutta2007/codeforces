#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int a[5],b[5];
int ans[5];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=3;i++)
        scanf("%d %d",&a[i],&b[i]);
    ans[1]=min(n-a[2]-a[3],b[1]);
    n-=ans[1];
    ans[2]=min(n-a[3],b[2]);
    ans[3]=n-ans[2];
    printf("%d %d %d\n",ans[1],ans[2],ans[3]);
    return 0;
}