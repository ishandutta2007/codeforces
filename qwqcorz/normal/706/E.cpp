#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
const int Q=1e4+5;

inline int read()
{
	register int s=0;
	register char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(register int x)
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
inline void print(const register int x,const register char c='\n')
{
	write(x);
	putchar(c);
}
int a[N][N],num[N][N],v[N*N],r[N*N],d[N*N],cnt=0,n,m,q;
int find(int x,int y)
{//print(x,' ');print(y);
	int now=num[0][0];
	for (int i=1;i<=x;i++) now=d[now];//print(now);
	for (int i=1;i<=y;i++) now=r[now];//print(now);
	return now;
}
void out(int x,int y,int now)
{
	if (x>n) return;
	if (y>m) return void(putchar('\n'));
	print(v[now],' ');
	out(x,y+1,r[now]);
	if (y==1) out(x+1,y,d[now]);
}

int main()
{
	n=read();
	m=read();
	q=read();
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++) a[i][j]=read();
	for (int i=0;i<=n;i++)
	for (int j=0;j<=m;j++) num[i][j]=++cnt;
	for (int i=0;i<=n;i++)
	for (int j=0;j<=m;j++)
	{
		int now=num[i][j];
		v[now]=a[i][j];
		r[now]=num[i][j+1];
		d[now]=num[i+1][j];
	}
	for (int i=1;i<=q;i++)
	{
		int x1=read(),y1=read(),x2=read(),y2=read(),x=read(),y=read();
		int now1=find(x1-1,y1-1),now2=find(x2-1,y2-1),tmp1=now1,tmp2=now2;
		//print(now1,' ');print(now2);print(num[2][2]);
		for (int i=1;i<=x;i++)
		{
			now1=d[now1];
			now2=d[now2];
			swap(r[now1],r[now2]);
		}
		for (int i=1;i<=y;i++)
		{
			now1=r[now1];
			now2=r[now2];
			swap(d[now1],d[now2]);
		}
		now1=tmp1;
		now2=tmp2;
		for (int i=1;i<=y;i++)
		{
			now1=r[now1];
			now2=r[now2];
			swap(d[now1],d[now2]);
		}
		for (int i=1;i<=x;i++)
		{
			now1=d[now1];
			now2=d[now2];
			swap(r[now1],r[now2]);
		}
	}
	out(1,1,r[d[num[0][0]]]);

	return 0;
}
/*
4 4 1
1 2 3 4
5 6 7 8
1 2 3 4
5 6 7 8
1 1 3 3 2 2
*/