#include<bits/stdc++.h>
using namespace std;
const int N=28;
const int S=(1<<24)+5;
const int p=1e9+7;

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
void add(int &x,int y)
{
	x+=y;
	if (x>=p) x-=p;
}
int a[N],b[6],w[S],sum[S],dp[S];

signed main()
{
	sum[0]=0;
	memset(w,0,sizeof(w));
	memset(dp,0,sizeof(dp));
	int n=read();
	for (int i=0;i<n;i++) a[i]=read();
	int m=read(),flag=1;
	for (int i=1;i<=m;i++) if ((b[i]=read())==0) flag=0;
	if (!flag) return print(0),0;
	dp[0]=1;
	for (int i=0;i<n;i++) w[1<<i]=i;
	for (int i=1;i<(1<<n);i++)
	{
		sum[i]=sum[i^(i&-i)]+a[w[i&-i]];
		flag=0;
		for (int j=1;j<=m;j++)
		if (sum[i]==b[j])
		{
			flag=1;
			break;
		}
		if (flag) continue;
		int now=i;
		while (now)
		{
			int j=now&-now;
			now^=j;
			add(dp[i],dp[i^j]);
		}
	}
	print(dp[(1<<n)-1]);

	return 0;
}