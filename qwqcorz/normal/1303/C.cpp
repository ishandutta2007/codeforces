#include<bits/stdc++.h>
using namespace std;
const int N=3e2;

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
char a[N],ans[N];
bool used[N];
void check(int n)
{
	memset(ans,0,sizeof(ans));
	memset(used,0,sizeof(used));
	int now=100,l=100,r=100;
	ans[100]=a[1];
	used[a[1]]=1;
	for (int i=2;i<=n;i++)
	{
		if (!used[a[i]])
		{
			if (now!=l&&now!=r) return void(puts("NO"));
			if (now==l) ans[l=--now]=a[i];
			else if (now==r) ans[r=++now]=a[i];
		}
		else
		{
			if (ans[now-1]==a[i])
			{
				now--;
				continue;
			}
			if (ans[now+1]==a[i])
			{
				now++;
				continue;
			}
			return void(puts("NO"));
		}
		used[a[i]]=1;
	}
	puts("YES");
	for (int i=l;i<=r;i++) putchar(ans[i]);
	for (int i='a';i<='z';i++) if (!used[i]) putchar(i);
	putchar('\n');
}

int main()
{
	int T=read();
	while (T--)
	{
		int n=0;
		char c=getchar();
		while (c<'a'||'z'<c) c=getchar();
		while ('a'<=c&&c<='z') a[++n]=c,c=getchar();
		check(n);
	}

	return 0;
}