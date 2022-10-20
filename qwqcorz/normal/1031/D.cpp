#include<bits/stdc++.h>
#define x first
#define y second
#define mk make_pair
using namespace std;
const int N=2e3+5;

char get()
{
	char c=getchar();
	while (c<'a'||'z'<c) c=getchar();
	return c;
}
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
vector<pair<int,int> >p[N*2];
int n,k,dp[N][N];
char a[N][N];
bool can[N][N];

signed main()
{
	p[0].push_back(mk(1,0));
	n=read();
	k=read();
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++) a[i][j]=get();
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++) p[i+j-1].push_back(mk(i,j));
	for (int i=1;i<=n*2-1;i++)
	for (int j=0;j<p[i].size();j++)
	{
		int nx=p[i][j].x,ny=p[i][j].y;
		dp[nx][ny]=max(dp[nx-1][ny],dp[nx][ny-1])+(a[nx][ny]=='a');
	}
	int Max=0;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	if (i+j-1-k<=dp[i][j])
	Max=max(Max,i+j-1);
	memset(can,0,sizeof(can));
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	if (i+j-1==Max&&i+j-1-k<=dp[i][j])
	can[i][j]=1;
	if (Max==0) can[0][1]=1;
	for (int i=1;i<=Max;i++) putchar('a');
	for (int i=Max+1;i<=n*2-1;i++)
	{
		char Min='z';
		for (int j=0;j<p[i].size();j++)
		{
			int nx=p[i][j].x,ny=p[i][j].y;
			if (can[nx-1][ny]||can[nx][ny-1]) Min=min(Min,a[nx][ny]);
		}
		putchar(Min);
		for (int j=0;j<p[i].size();j++)
		{
			int nx=p[i][j].x,ny=p[i][j].y;
			if ((can[nx-1][ny]||can[nx][ny-1])&&a[nx][ny]==Min) can[nx][ny]=1;
		}
//		puts("");
//		for (int i=0;i<=n;i++,puts(""))
//		for (int j=0;j<=n;j++) putchar(can[i][j]+'0');
//		puts("");
	}
//	puts("");
//	for (int i=1;i<=n;i++,puts(""))
//	for (int j=1;j<=n;j++) putchar(can[i][j]+'0');

	return 0;
}
/*
5 0
irkda
thmek
abaqa
uswau
aaaaa
*/