#include<bits/stdc++.h>
using namespace std;
const int N=5e2+5;

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
char get()
{
	char c=getchar();
	while (c!='.'&&c!='*') c=getchar();
	return c;
}
char a[N][N];
int s[N][N];

signed main()
{
	int T=read();
	while (T--)
	{
		int n=read(),m=read(),ans=0;
		for (int i=1;i<=n;i++) s[i][0]=0;
		for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) a[i][j]=get();
		for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) s[i][j]=s[i][j-1]+(a[i][j]=='*');
		for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		for (int k=0;i+k<=n;k++)
		{
			if (j-k<1||m<j+k||s[i+k][j+k]-s[i+k][j-k-1]!=k*2+1) break;
			ans++;
		}
		print(ans);
	}

	return 0;
}