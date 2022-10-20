#include<bits/stdc++.h>
using namespace std;

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
priority_queue<int>q;

int main()
{
	int T=read();
	while (T--)
	{
		while (!q.empty()) q.pop();
		int n=read();
		for (int i=1;i<=n;i++)
		{
			int x=read();
			q.push(x);
		}
		int x=0;
		while (!q.empty())
		{
			int x1=q.top()-1;
			q.pop();
			if (x) q.push(x);
			if (q.empty())
			{
				puts("T");
				break;
			}
			int x2=q.top()-1;
			q.pop();
			if (x1) q.push(x1);
			if (q.empty())
			{
				puts("HL");
				break;
			}
			x=x2;
		}
	}

	return 0;
}