#include<bits/stdc++.h>
using namespace std;
const int N=28;

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
int n,m,q;
char a[N][N],b[N][N];

int main()
{
	n=read();
	m=read();
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=m;i++) cin>>b[i];
	q=read();
	for (int i=1;i<=q;i++)
	{
		int y=read(),l=y%n,r=y%m;
		if (l==0) l=n;
		if (r==0) r=m;
		for (int i=0;a[l][i]!='\0';i++) putchar(a[l][i]);
		for (int i=0;b[r][i]!='\0';i++) putchar(b[r][i]);
		putchar('\n');
	}

	return 0;
}