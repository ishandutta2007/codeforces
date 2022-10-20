#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=15;
const int M=(1<<13)+5;
const int Q=1e2+5;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(ll x)
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
void print(ll x,char c='\n')
{
	write(x);
	putchar(c);
}
int u[N],v[N],a[Q],b[Q],c[Q];
ll dp[M][N];
//bool inside (int S,int x){return (S >> x & 1);}

signed main()
{
	int n=read(),m=read(),q=read();
	for (int i=1;i<=m;i++)
	{
		u[i]=read()-1;
		v[i]=read()-1;
	}
	for (int i=1;i<=q;i++)
	{
		a[i]=read()-1;
		b[i]=read()-1;
		c[i]=read()-1;
	}
	memset(dp,0,sizeof(dp));
	for (int i=0;i<n;i++) dp[1<<i][i]=1;
	for (int s=0;s<(1<<n);s++)
	for (int i=0;i<n;i++)
	if (s&(1<<i))
	{
		int pos=114514;
		for (int j=0;j<n;j++)
		if (i!=j&&(s&(1<<j)))
		{
			pos=j;
			break;
		}
//		print(pos);
//		if (pos<0) continue;
//		pos=1<<pos;
		int nowS=s^(1<<i);
		for (int sub=nowS;sub;sub=(sub-1)&nowS)
		if ((sub>>pos)&1)
		{
//			print(sub);
			bool flag=0;
			int s1=s^sub,s2=sub,can=-1,cnt=0;
			for (int j=1;j<=m;j++)
			{
				if (u[j]==i)
				{
					if (s2&(1<<v[j]))
					{
						cnt++;
						can=v[j];
					}
					continue;
				}
				if (v[j]==i)
				{
					if (s2&(1<<u[j]))
					{
						cnt++;
						can=u[j];
					}
					continue;
				}
				if ((s2&(1<<u[j]))&&!(s2&(1<<v[j])))
				{
					flag=1;
					break;
				}
				if (!(s2&(1<<u[j]))&&(s2&(1<<v[j])))
				{
					flag=1;
					break;
				}
			}
			if (cnt>1||flag) continue;
			for (int j=1;j<=q;j++)
			if (!(s2&(1<<a[j]))||!(s2&(1<<b[j])))
			if (s2&(1<<c[j]))
			{
				flag=1;
				break;
			}
			for (int j=1;j<=q;j++)
			if ((s2&(1<<a[j]))&&(s2&(1<<b[j])))
			if (c[j]==i)
			{
				flag=1;
				break;
			}
//			print(flag);
//		for (int j = 1;j <= q;++ j){
//			if (c[j] == i && inside (s2,a[j]) && inside (s2,b[j])){flag = 1;break;}
//			if (inside (s2,c[j]) && (!inside (s2,a[j]) || !inside (s2,b[j]))){flag = 1;break;}
//		}
			if (flag) continue;
//			if (s==(1<<n)-1&&i==0) puts("XXX");
//			print(s1,' '),print(s2);
			if (can>=0) dp[s][i]+=dp[s1][i]*dp[s2][can]; 
			else for (int j=0;j<n;j++) dp[s][i]+=dp[s1][i]*dp[s2][j];
		}
	}
//	for (int i=0;i<n;i++,puts(""))
//	for (int j=0;j<(1<<n);j++) write(dp[j][i]),putchar(' ');
	print(dp[(1<<n)-1][0]);

	return 0;
}