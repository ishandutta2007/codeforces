#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef double db;
const int MAXN=20;
const db PI=acos(-1.0);
const db inf=1e12;
const db eps=1e-9;
db cal(db x,db y,db a,db l)
{
    db t=atan2(-y,l-x);
    if(t+a>-eps)return inf;
    return x+y*tan(t+a+PI/2);
}
db x[MAXN],y[MAXN],a[MAXN],dp[1<<MAXN];
int main()
{
    int n;
    db l,r;
    scanf("%d%lf%lf",&n,&l,&r);
    for(int i=0;i<n;i++)
        scanf("%lf%lf%lf",&x[i],&y[i],&a[i]),a[i]=a[i]*PI/180;
    for(int i=0;i<(1<<n);i++)
        dp[i]=l;
    for(int i=0;i<(1<<n);i++)
        for(int j=0;j<n;j++)if(~i&(1<<j))
            dp[i|(1<<j)]=max(dp[i|(1<<j)],cal(x[j],y[j],a[j],dp[i]));
    return 0*printf("%.9f",min(dp[(1<<n)-1],r)-l);
}