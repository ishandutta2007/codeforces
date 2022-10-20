#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5;
const int inf=INT_MAX/3;

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
int a[N];
queue<int>q;

int main()
{
	for (int i=0;i<=2000;i++) a[i]=inf;
	int m=read(),n=read();
	for (int i=1;i<=n;i++) a[read()-m+1000]=1;
	for (int i=0;i<=2000;i++) if (a[i]==1) q.push(i);
	while (q.size())
	{
		int qwq=q.front();
		q.pop();
		for (int i=0;i<=2000;i++)
		if (a[i]==1&&a[i+qwq-1000]==inf)
		{
			a[i+qwq-1000]=a[qwq]+1;
			q.push(i+qwq-1000);
		}
	}
	if (a[1000]<inf) print(a[1000]);
				else puts("-1");

	return 0;
}