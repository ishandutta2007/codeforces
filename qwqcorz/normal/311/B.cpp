#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
const int P=1e2+5;
const double inf=1e16;

inline int read()
{
	register int s=0;
	register char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(register int x)
{
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x<10) putchar(x+'0');
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
inline void print(const register int x,const register char c='\n')
{
	write(x);
	putchar(c);
}
inline double slope(double x1,double y1,double x2,double y2)
{
	if (x1==x2) return y1<y2?inf:-inf;
	return (y2-y1)/(x2-x1);
}
int d[N],a[N],s[N],dp[N][P],x[N],y[N],h,t;
inline void add(int nx,int ny)
{
	while (h<t&&slope(x[t-1],y[t-1],x[t],y[t])>=slope(x[t],y[t],nx,ny)) t--;
	x[++t]=nx;
	y[t]=ny;
}
inline void pop(int Max)
{
	while (h<t&&slope(x[h],y[h],x[h+1],y[h+1])<=Max) h++;
}

signed main()
{
	d[0]=s[0]=0;
	int n=read(),m=read(),p=read();//n:m:p: 
	for (int i=2;i<=n;i++) d[i]=d[i-1]+read();
	for (int i=1;i<=m;i++)
	{
		int h=read(),t=read();
		a[i]=t-d[h];
		s[i]=s[i-1]+a[i];
	}
	sort(a+1,a+1+m);
	for (int i=1;i<=m;i++) dp[i][1]=a[i]*i-s[i];
	for (int j=2;j<=p;j++)
	{
		h=1;
		t=0;
		for (int i=1;i<=m;i++)
		{
			add(i,dp[i][j-1]+s[i]);
			pop(a[i]);
			dp[i][j]=dp[x[h]][j-1]+a[i]*(i-x[h])-(s[i]-s[x[h]]);
		}
	}
	print(dp[m][p]);

	return 0;
}