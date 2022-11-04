#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int a[3005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    int now=a[1]-1,ans=0;
    for(int i=1;i<=n;i++)
    {
        while(a[i]<=now)
        {
            ans++;
            a[i]++;
        }
        now=a[i];
    }
    printf("%d\n",ans);
    return 0;
}