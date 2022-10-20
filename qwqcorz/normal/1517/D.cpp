#include<bits/stdc++.h>
using namespace std;
const int N=505;

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
int eh[N][N],ez[N][N],dis[N][N][15];
inline void up(int &x,int y)
{
	x=min(x,y);
}

signed main()
{
	int n=read(),m=read(),k=read();
	if (k&1)
	{
		for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) putchar('-'),putchar('1'),putchar(j%m?' ':'\n');
		return 0;
	}
	for (int i=1;i<=n;i++)
	for (int j=1;j<m;j++)
	eh[i][j]=read();
	for (int i=1;i<n;i++)
	for (int j=1;j<=m;j++)
	ez[i][j]=read();
	for (int t=0;t<k/2;t++)
	{
		for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) dis[i][j][t+1]=1e9+7;
		for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			if (i<n) up(dis[i+1][j][t+1],dis[i][j][t]+ez[i][j]);
			if (i>1) up(dis[i-1][j][t+1],dis[i][j][t]+ez[i-1][j]);
			if (j<m) up(dis[i][j+1][t+1],dis[i][j][t]+eh[i][j]);
			if (j>1) up(dis[i][j-1][t+1],dis[i][j][t]+eh[i][j-1]);
		}
	}
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++) print(dis[i][j][k/2]*2,j%m?' ':'\n');

	return 0;
}