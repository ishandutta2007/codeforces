#include<bits/stdc++.h>
using namespace std;
const int N=105;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};

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
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
int a[N][N];
bool check(int i,int j,int x)
{
	for (int k=0;k<4;k++)
	if (x==a[i+dx[k]][j+dy[k]])
	return 0;
	return 1;
}
int get(int i,int j)
{
	int k;
	for (k=1;!check(i,j,k);k++);
	return k;
}

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	int n=read(),m=read();
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
	if (!a[i][j])
	{
		int now=get(i,j),len=0;
		for (int k=1;i+k<=n&&j+k<=m;k++)
		{
			if (a[i][j+k]) break;
			if (!check(i,j+k,now)) break;
			if (get(i,j+k)<now) break;
			len=k;
		}
		for (int x=i;x<=i+len;x++)
		for (int y=j;y<=j+len;y++)
		a[x][y]=now;
	}
	for (int i=1;i<=n;i++,puts(""))
	for (int j=1;j<=m;j++)
	putchar(a[i][j]+'A'-1);
	
	return 0;
}