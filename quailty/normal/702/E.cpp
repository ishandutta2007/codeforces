#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=100005;
ll f[MAXN],w[MAXN],nxt[MAXN][35],sum[MAXN][35],mi[MAXN][35];
int main()
{
    ll n,k;
    scanf("%I64d%I64d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%I64d",&f[i]);
    for(int i=0;i<n;i++)
        scanf("%I64d",&w[i]);
    for(int i=0;i<n;i++)
        nxt[i][0]=f[i],sum[i][0]=mi[i][0]=w[i];
    for(int _=1;_<35;_++)
        for(int i=0;i<n;i++)
        {
            nxt[i][_]=nxt[nxt[i][_-1]][_-1];
            sum[i][_]=sum[i][_-1]+sum[nxt[i][_-1]][_-1];
            mi[i][_]=min(mi[i][_-1],mi[nxt[i][_-1]][_-1]);
        }
    for(int i=0;i<n;i++)
    {
        ll rsum=0,rmi=(1LL<<30)-1;
        for(int p=i,j=34;j>=0;j--)
            if(k&(1LL<<j))
            {
                rsum+=sum[p][j];
                rmi=min(rmi,mi[p][j]);
                p=nxt[p][j];
            }
        printf("%I64d %I64d\n",rsum,rmi);
    }
    return 0;
}