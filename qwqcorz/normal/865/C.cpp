#include<bits/stdc++.h>
#define mid (l+r)/2
using namespace std;
const int N=55;
const int M=N*100;
const double eps=1e-9;
 
inline int read()
{
    int s=0;
    char c=getchar(),lc='+';
    while (c<'0'||c>'9') lc=c,c=getchar();
    while (c>='0'&&c<='9') s=s*10+c-'0',c=getchar();
    return lc=='-'?-s:s;
}
int n,m,a[N],b[N],p[N];
double f[N][M];
bool check(double k)
{
    for (int i=n;i>=1;i--)
    {
        for (int j=m+1;j<M;j++) f[i+1][j]=k;
        for (int j=0;j<=m;j++) f[i][j]=min((f[i+1][j+a[i]]+a[i])*p[i]/100+(f[i+1][j+b[i]]+b[i])*(100-p[i])/100,k);
    }
    return f[1][0]<k;
}
 
int main()
{
    n=read();
    m=read();
    for (int i=1;i<=n;i++)
    {
        a[i]=read();
        b[i]=read();
        p[i]=read();
    }
    double l=0,r=1e9;
    for (int i=1;i<=100;i++)
    {
	    if (check(mid)) r=mid;
	               else l=mid;
	}
    printf("%.10f",r);
 
    return 0;
}