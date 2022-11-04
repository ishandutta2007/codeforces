#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=105;
int a[MAXN],s[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    s[0]=10;
    for(int i=1;i<=n;i++)
        s[i]=s[i-1]+a[i];
    int res=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i]>720)break;
        res=i;
    }
    int sum=0;
    for(int i=1;i<=res;i++)
        sum+=max(0,s[i]-360);
    printf("%d %d",res,sum);
    return 0;
}