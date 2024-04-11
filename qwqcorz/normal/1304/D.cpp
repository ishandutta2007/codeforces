#include<bits/stdc++.h>
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
char a[N];
int ans[N];

int main()
{
	int T=read();
	while (T--)
	{
		int n=read();
		for (int i=1;i<n;i++)
		{
			char c=getchar();
			while (c!='<'&&c!='>') c=getchar();
			a[i]=c;
		}
		for (int i=1;i<=n;i++) ans[i]=0;
		a[n]='>';
		int now=n;
		for (int i=1;i<n;i++)
		if (a[i]=='<'&&a[i+1]=='>')
		{
			int x=i;
			while (a[x]=='<')
			{
				ans[x+1]=now--;
				x--;
			}
		}
		for (int i=1;i<=n;i++) if (ans[i]==0) ans[i]=now--;
		for (int i=1;i<=n;i++) print(ans[i],' ');
		putchar('\n');
		////////////////////////////////////////////////////
		now=n;
		for (int i=1;i<=n;i++) ans[i]=0;
		for (int i=n-1;i>=1;i--) if (a[i]=='<') ans[i+1]=now--;
		for (int i=1;i<=n;i++) if (ans[i]==0) ans[i]=now--;
		for (int i=1;i<=n;i++) print(ans[i],' ');
		putchar('\n');
	}

	return 0;
}