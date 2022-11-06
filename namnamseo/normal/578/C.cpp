#include <cstdio>

int n;
long long p[200010];

double max(double a,double b){ return a>b?a:b; }
double min(double a,double b){ return a<b?a:b; }

double work(double x)
{
    int i;
    double cmin=0, cmax=0, cur;
    for(i=1;i<=n;++i)
    {
        cur=p[i]-i*x;
        cmin=min(cmin,cur);
        cmax=max(cmax,cur);
    }
    return cmax-cmin;
}

int main()
{
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;++i) scanf("%I64d",p+i), p[i]+=p[i-1];
    double l=-1e7, a, b, r=1e7;
    for(i=0;i<1000;++i)
    {
        a=(l*2+r)/3;
        b=(r*2+l)/3;
        if(work(a)>work(b)) l=a;
        else r=b;
    }
    printf("%.10f\n",work(a));
    return 0;
}