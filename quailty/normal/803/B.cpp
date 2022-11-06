#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=200005;
const int INF=0x3f3f3f3f;
int a[MAXN],lef[MAXN],rig[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int la=-INF;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==0)la=i;
        lef[i]=i-la;
    }
    la=INF;
    for(int i=n;i>=1;i--)
    {
        if(a[i]==0)la=i;
        rig[i]=la-i;
    }
    for(int i=1;i<=n;i++)
        printf("%d ",min(lef[i],rig[i]));
    return 0;
}