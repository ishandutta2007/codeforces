#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int B=233;

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
int x[N],y[N],len[N],c[N][B],t[N],p[N];

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read(),m=read();
	for (int i=1;i<=n;i++) x[i]=read(),y[i]=read(),len[i]=x[i]+y[i];
	for (int i=1;i<=m;i++)
	{
		int opt=read(),k=read(),pos=i,Add=opt==1?1:-1;
		int dx=x[k],dy=y[k],dl=len[k];
		if (opt==2)
		{
			pos+=(p[k]%dl-i%dl+dl)%dl;
			if (i<=pos-dy-1) c[i][1]--,c[min(pos-dy,m+1)][1]++;
		}
		else p[k]=i;
		t[i]+=Add;
		if (dl>=B)
		while (pos<=m)
		{
			c[pos][1]+=Add;
			c[min(pos+dx,m+1)][1]-=Add;
			pos+=dl;
		}
		else for (int i=0;i<dx&&pos+i<=m;i++) c[pos+i][dl]+=Add;
	}
	for (int i=1;i<=m;i++) t[i]+=t[i-1];
	for (int i=1;i<=m;i++)
	for (int j=1;j<B&&i+j<=m;j++)
	c[i+j][j]+=c[i][j];
	for (int i=1;i<=m;i++)
	{
		int now=0;
		for (int j=1;j<B;j++) now+=c[i][j];
		print(t[i]-now);
	}
	
	return 0;
}
/*
3 1
10 15
12 10
1 1
1 3
1 1
2 1
2 3
*/