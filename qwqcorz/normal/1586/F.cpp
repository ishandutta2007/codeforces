#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;

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
int e[N][N];

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read(),k=read(),now=1,col=0;
	do
	{
		int tmp=now;
		col++;
		now*=k;
		for (int i=1;i<=n;i++)
		for (int j=i+1;j<=min(i+now,n);j++)
		if ((i-1)/now==(j-1)/now&&(i-1)/tmp!=(j-1)/tmp)
		e[i][j]=col;
	}while (now<n);
	print(col);
	for (int i=1;i<=n;i++)
	for (int j=i+1;j<=n;j++) print(e[i][j],' ');
	
	return 0;
}