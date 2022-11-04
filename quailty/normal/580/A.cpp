#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int a[100005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int ans=0,now=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>=a[i-1])now++;
        else now=1;
        ans=max(ans,now);
    }
    printf("%d\n",ans);
    return 0;
}