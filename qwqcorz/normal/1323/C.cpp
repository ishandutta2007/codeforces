#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;

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
int st[N];

int main()
{
	int n=read(),top=0,p=0,ans=0;
	for (int i=1;i<=n;i++)
	{
		char c=getchar();
		while (c!='('&c!=')') c=getchar();
		if (top==0)
		{
			st[top=1]=c;
			if (c==')') p=i;
		}
		else if (st[top]=='(')
		{
			if (c=='(') st[++top]=c;
				   else top--;
		}
		else
		{
			if (c==')') st[++top]=c;
			else
			{
				top--;
				if (top==0) ans+=i-p+1;
			}
		}
	}
	if (top) print(-1);
		else print(ans);

	return 0;
}