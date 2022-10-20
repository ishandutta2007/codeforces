#include<bits/stdc++.h>
using namespace std;
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
map<int,bool>m;

int main()
{
	int T=read();
	while (T--)
	{
		m.clear();
		int n=read(),ans=0;
		for (int i=1;i<=n;i++)
		{
			int a=read();
			while (a%2==0&&!m[a])
			{
				m[a]=1;
				a/=2;
				ans++;
			}
		}
		print(ans);
	}

	return 0;
}