#include<cstdio>
#include<algorithm>
#define eps 1e-10
using namespace std;
int n,i,j,l,ln;
double a[110],x,y;
int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%lf",&a[i]);
    sort(a+1,a+n+1);x=0;y=1;
    for(;n;n--)
    {
        if(x*(1-a[n])+y*a[n]<x)break;
        x=x*(1-a[n])+y*a[n];y=y*(1-a[n]);
    }printf("%.10lf\n",x);
}