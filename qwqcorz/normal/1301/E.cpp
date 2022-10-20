#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int M=3e5+5;

int get()
{
	char c=getchar();
	while (c<'A'||'Z'<c) c=getchar();
	switch (c)
	{
		case 'R':return 0;
		case 'G':return 1;
		case 'Y':return 2;
		case 'B':return 3;
	}
	return 114514;
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
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
struct Query
{
	int x1,y1,x2,y2;
}q[M];
int len[N][N],ans[M],sum[4][N][N],a[N][N];
bool check(int k,int x1,int x2,int y1,int y2)
{
	return sum[k][x1][y1]-sum[k][x2][y1]-sum[k][x1][y2]+sum[k][x2][y2]==(x2-x1)*(y2-y1);
}
bool check2(int x1,int y1,int x2,int y2)
{
	return a[x2][y2]-a[x2][y1-1]-a[x1-1][y2]+a[x1-1][y1-1];
}

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	int n=read(),m=read(),Q=read();
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
	sum[get()][i][j]++;
	for (int k=0;k<4;k++)
	for (int i=n;i>=1;i--)
	for (int j=m;j>=1;j--)
	sum[k][i][j]+=sum[k][i+1][j]+sum[k][i][j+1]-sum[k][i+1][j+1];
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
	for (int k=1;i+2*k-1<=n&&j+2*k-1<=m;k++)
	if (check(0,i,i+k,j,j+k)&&
		check(1,i,i+k,j+k,j+k*2)&&
		check(2,i+k,i+k*2,j,j+k)&&
		check(3,i+k,i+k*2,j+k,j+k*2)) len[i][j]=k;
	for (int i=1;i<=Q;i++)
		q[i].x1=read(),
		q[i].y1=read(),
		q[i].x2=read(),
		q[i].y2=read();
	for (int k=1;k<=min(n,m)/2;k++)
	{
		for (int i=1;i+k*2-1<=n;i++)
		for (int j=1;j+k*2-1<=m;j++)
		a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+(len[i][j]==k);
		for (int i=1;i<=Q;i++)
		if (q[i].x2-q[i].x1+1>=k*2)
		if (q[i].y2-q[i].y1+1>=k*2)
		if (check2(q[i].x1,q[i].y1,q[i].x2-k*2+1,q[i].y2-k*2+1))
		ans[i]=k;
	}
	for (int i=1;i<=Q;i++) print(ans[i]*ans[i]*4);
	
	return 0;
}