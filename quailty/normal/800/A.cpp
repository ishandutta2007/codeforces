#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef double db;
const int MAXN=100005;
int a[MAXN],b[MAXN];
int main()
{
    int n,p;
    scanf("%d%d",&n,&p);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i],&b[i]);
    db l=0,r=1e18;
    for(int _=0;_<100;_++)
    {
        db m=(l+r)/2,sum=0;
        for(int i=1;i<=n;i++)
            sum+=max(0.0,a[i]*m-b[i])/p;
        if(sum>m)r=m;
        else l=m;
    }
    if(l>1e16)printf("-1\n");
    else printf("%.12f\n",l);
    return 0;
}