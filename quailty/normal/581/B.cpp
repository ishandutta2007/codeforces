#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
int a[MAXN],ans[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int Max=a[n];
    for(int i=n-1;i>=1;i--)
    {
        ans[i]=max(Max+1-a[i],0);
        if(Max<a[i])Max=a[i];
    }
    for(int i=1;i<=n;i++)
        printf("%d ",ans[i]);
    return 0;
}