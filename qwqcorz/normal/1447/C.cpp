#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(int x)
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
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
int w[N],id[N];
void solve()
{
	int n=read(),W=read(),sum=0,m=0;
	for (int i=1;i<=n;i++)
	{
		int x=read();
		if (x>W) /*nothing*/;
		else if (x>=(W+1)/2)
		{
			print(1);
			print(i);
			for (int j=i+1;j<=n;j++) x=read();
			return;
		}
		else
		{
			w[++m]=x;
			id[m]=i;
		}
	}
	for (int i=1;i<=m;i++)
	{
		sum+=w[i];
		if (sum>=(W+1)/2)
		{
			print(i);
			for (int j=1;j<=i;j++) print(id[j],' ');
			puts("");
			return;
		}
	}
	print(-1);
	return;
}

signed main()
{
	int T=read();
	while (T--) solve();

	return 0;
}