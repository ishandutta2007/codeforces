#include<bits/stdc++.h>
using namespace std;
const int N=55;
const int K=26;

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
void print(int x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
int get()
{
	char c=getchar();
	while (c<'a'||'z'<c) c=getchar();
	return c-'a';
}
char c[N];
int a[N],b[N],f[N],t1[N],t2[N],n,m;
void init(int *a,int &n)
{
	scanf("%s",c+1);
	n=strlen(c+1);
	for (int i=1;i<=n;i++) a[i]=c[i]-'a';
}
bool cana[N][N][K],canb[N][N][K];
int dp[N][N];

signed main(int Recall,char *_902_[])
{
	init(a,n);
	init(b,m);
	int p=read();
	for (int i=1;i<=p;i++)
	{
		f[i]=get();
		t1[i]=get();
		t2[i]=get();
	}
	memset(cana,0,sizeof(cana));
	for (int i=1;i<=n;i++) cana[i][i][a[i]]=1;
	for (int i=2;i<=n;i++)
	for (int j=1;i+j-1<=n;j++)
	for (int t=1;t<=p;t++)
	{
		int l=j,r=i+j-1;
		for (int k=l;k<r;k++)
		cana[l][r][f[t]]|=cana[l][k][t1[t]]&&cana[k+1][r][t2[t]];
	}
	memset(canb,0,sizeof(canb));
	for (int i=1;i<=m;i++) canb[i][i][b[i]]=1;
	for (int i=2;i<=m;i++)
	for (int j=1;i+j-1<=m;j++)
	for (int t=1;t<=p;t++)
	{
		int l=j,r=i+j-1;
		for (int k=l;k<r;k++)
		canb[l][r][f[t]]|=canb[l][k][t1[t]]&&canb[k+1][r][t2[t]];
	}
	memset(dp,0x3f,sizeof(dp));
	const int inf=dp[0][0];
	dp[0][0]=0;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
	for (int x=1;x<=i;x++)
	for (int y=1;y<=j;y++)
	for (int k=0;k<26;k++)
	if (cana[x][i][k]&&canb[y][j][k])
	dp[i][j]=min(dp[i][j],dp[x-1][y-1]+1);
	if (dp[n][m]<inf) print(dp[n][m]);
				 else print();

	return 0;
}