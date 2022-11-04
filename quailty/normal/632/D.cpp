#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1000005;
const int MAXM=1000005;
int gcd(int a,int b)
{
    return a==0 ? b : gcd(b,a%b);
}
int lcm(int a,int b)
{
    return a/gcd(a,b)*b;
}
int a[MAXN],c[MAXM];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        if(a[i]<=m)
            c[a[i]]++;
    for(int i=m;i>=1;i--)
        for(int j=2*i;j<=m;j+=i)
            c[j]+=c[i];
    int res=0,loc=m;
    for(int i=m;i>=1;i--)
        if(c[i]>=res)
        {
            res=c[i];
            loc=i;
        }
    printf("%d %d\n",loc,res);
    for(int i=1;i<=n;i++)
        if(loc%a[i]==0)
            printf("%d ",i);
    return 0;
}