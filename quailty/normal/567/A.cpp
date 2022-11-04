#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int a[100005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        int Min=0x7fffffff,Max=0;
        if(i>1)Min=min(Min,abs(a[i]-a[i-1]));
        if(i<n)Min=min(Min,abs(a[i]-a[i+1]));
        Max=max(abs(a[i]-a[1]),abs(a[i]-a[n]));
        printf("%d %d\n",Min,Max);
    }
    return 0;
}