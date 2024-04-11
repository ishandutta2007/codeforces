#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int a[200005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int mi=~0U>>1,cnt=0;
    for(int i=1;i<n;i++)
    {
        if(mi>a[i+1]-a[i])mi=a[i+1]-a[i],cnt=0;
        cnt+=(a[i+1]-a[i]==mi);
    }
    printf("%d %d\n",mi,cnt);
    return 0;
}