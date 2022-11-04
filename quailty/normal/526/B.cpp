#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int a[(1<<12)-1];
int t[(1<<12)-1];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=2;i<=(1<<n+1)-1;i++)
    {
        scanf("%d",&a[i]);
    }
    int ans=0;
    for(int i=(1<<n+1)-1;i>=2;i--)
    {
        if(i%2)
        {
            t[i/2]=max(t[i]+a[i],t[i-1]+a[i-1]);
            ans+=t[i/2]-min(t[i]+a[i],t[i-1]+a[i-1]);
        }
    }
    printf("%d\n",ans);
    return 0;
}