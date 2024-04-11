#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;

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
bool b[N];
char a[N];
bool check1(int n)
{
	for (int i=1;i<=n;i++) if (a[i]=='<') return 0;
	return 1;
}
bool check2(int n)
{
	for (int i=1;i<=n;i++) if (a[i]=='>') return 0;
	return 1;
}

signed main()
{
	int T=read();
	while (T--)
	{
		int n=read();
		scanf("%s",a+1);
		if (check1(n)||check2(n)) print(n);
		else
		{
			for (int i=1;i<=n;i++) b[i]=0;
			for (int i=1;i<=n;i++)
			if (a[i]=='-')
			{
				b[i]=1;
				int nxt=i+1;
				if (nxt>n) nxt=1;
				b[nxt]=1;
			}
			int ans=0;
			for (int i=1;i<=n;i++) ans+=b[i];
			print(ans);
		}
	}

	return 0;
}