#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;

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
int n,OR[N],AND[N],a[N];
bool check(int st,bool flag)
{
	a[1]=st;
	for (int i=1;i<n;i++)
	{
		bool Flag=0;
		for (int j=0;j<=3;j++)
		if ((a[i]|j)==OR[i]&&(a[i]&j)==AND[i])
		{
			a[i+1]=j;
			Flag=1;
		}
		if (!Flag) return 0;
	}
	if (flag)
	{
		puts("YES");
		for (int i=1;i<=n;i++) print(a[i],' ');
	}
	return 1;
}

signed main()
{
	n=read();
	for (int i=1;i<n;i++) OR[i]=read();
	for (int i=1;i<n;i++) AND[i]=read();
	for (int i=0;i<=3;i++) if (check(i,0)) return !check(i,1);
	puts("NO");

	return 0;
}