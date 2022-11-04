#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long double ldb;
const int MAXN=200005;
const ldb eps=1e-8;
double in[MAXN];
ldb t[MAXN],sum[MAXN],fac[MAXN],pre[MAXN];
void prepare(int n)
{
    for(int i=1;i<=n;i++)
        t[i]=in[i];
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+t[i];
        fac[i]=fac[i-1]+1.0/t[i];
    }
    for(int i=1;i<=n;i++)
        pre[i]=pre[i-1]+sum[i]/t[i];
}
ldb cal(int l,int r)
{
    return pre[r]-pre[l-1]-sum[l-1]*(fac[r]-fac[l-1]);
}
struct Point
{
    ldb x,y;
    Point(){}
    Point(ldb _x,ldb _y):x(_x),y(_y){}
    Point operator - (const Point &t)const
    {
        return Point(x-t.x,y-t.y);
    }
    ldb operator * (const Point &t)const
    {
        return x*t.y-y*t.x;
    }
    ldb operator ^ (const Point &t)const
    {
        return x*t.x+y*t.y;
    }
}stk[MAXN];
int top=0;
ldb dp[2][MAXN];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%lf",&in[i]);
    prepare(n);
    int now=1,la=0;
    for(int i=1;i<=n;i++)
        dp[now][i]=cal(1,i);
    for(int i=2;i<=k;i++)
    {
        swap(now,la);
        top=0;
        for(int j=i;j<=n;j++)
        {
            Point p=Point(sum[j-1],dp[la][j-1]-pre[j-1]+sum[j-1]*fac[j-1]);
            Point q=Point(-fac[j],1);
            while(top>1 && (p-stk[top-1])*(stk[top-1]-stk[top-2])>eps)top--;
            stk[top++]=p;
            int l=0,r=top-1;
            while(l<r)
            {
                int m1=(2*l+r)/3;
                int m2=(l+2*r+2)/3;
                if((q^stk[m1])<(q^stk[m2]))r=m2-1;
                else l=m1+1;
            }
            dp[now][j]=(q^stk[l])+pre[j];
        }
    }
    printf("%.12f",(double)dp[now][n]);
    return 0;
}