#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a[105],b[105],w[105][105],e[105][105];
ll gcd(ll a,ll b)
{
    return b ? gcd(b,a%b) : a;
}
void ok(int n,int m,ll k)
{
    printf("YES\n%I64d\n",k);
    for(int i=1;i<=n;i++)
        printf("%I64d%c",a[i]%k+k," \n"[i==n]);
    for(int i=1;i<=m;i++)
        printf("%I64d%c",b[i]%k+k," \n"[i==m]);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%I64d",&w[i][j]);
    for(int j=1;j<=m;j++)
        b[j]=w[1][j];
    for(int i=1;i<=n;i++)
        a[i]=w[i][1]-w[1][1];
    ll mx=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            mx=max(mx,e[i][j]=abs(a[i]+b[j]-w[i][j]));
    if(!mx)
    {
        ll k=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                k=max(k,w[i][j]+1);
        ok(n,m,k);
    }
    else
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                mx=gcd(mx,e[i][j]);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(mx<=w[i][j])return 0*printf("NO");
        ok(n,m,mx);
    }
    return 0;
}