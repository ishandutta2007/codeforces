#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
const int INF=0x3f3f3f3f;
int a[MAXN],p[MAXN],q[MAXN],res[MAXN];
int main()
{
    int n,l,r;
    scanf("%d%d%d",&n,&l,&r);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&p[i]);
    for(int i=1;i<=n;i++)
        q[p[i]]=i;
    int la=-INF;
    for(int ii=1;ii<=n;ii++)
    {
        int i=q[ii];
        if(r-a[i]<=la)return 0*printf("-1");
        res[i]=max(l,la+1+a[i]);
        la=res[i]-a[i];
    }
    for(int i=1;i<=n;i++)
        printf("%d ",res[i]);
    return 0;
}