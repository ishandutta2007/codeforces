#include<bits/stdc++.h>
using namespace std;
const int N=105;
const int M=55;

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
	while (c<'a'||'z'<c) c=getchar();
	return c;
}
int an[N],now=0;
char a[N][M];
bool used[N];
bool check(int x,int y,int m)
{
	for (int i=1;i<=m;i++)
	if (a[x][i]!=a[y][m-i+1]) return 0;
	return 1;
}

int main()
{
	memset(an,0,sizeof(an));
	memset(used,0,sizeof(used));
	int n=read(),m=read(),ans=0;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++) a[i][j]=get();
	for (int i=1;i<=n;i++)
	if (!used[i])
	for (int j=i+1;j<=n;j++)
	if (!used[j]&&check(i,j,m))
	{
		used[i]=used[j]=1;
		ans+=2;
		now++;
		an[now]=i;
		an[n-now+1]=j;
	}
	for (int i=1;i<=n;i++)
	if (!used[i])
	{
		bool b=1;
		for (int j=1;j<=m/2;j++)
		if (a[i][j]!=a[i][m-j+1])
		{
			b=0;
			break;
		}
		if (b)
		{
			now++;
			ans++;
			an[now]=i;
			break;
		}
	}
	print(ans*m);
	for (int i=1;i<=n;i++)
	if (an[i])
	for (int j=1;j<=m;j++) putchar(a[an[i]][j]);

	return 0;
}