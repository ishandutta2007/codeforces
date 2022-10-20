#include<bits/stdc++.h>
using namespace std;
const int N=2e6;

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
char a[N];
int del[N];

int main()
{
	int T=read();
	while (T--)
	{
		int n=0,ans=0;
		char c=getchar();
		while (c<'a'||'z'<c) c=getchar();
		while ('a'<=c&&c<='z') a[++n]=c,c=getchar();
		a[n+1]=0;
		for (int i=3;i<=n;i++)
		{
			if (a[i-2]=='o'&&a[i-1]=='n'&&a[i]=='e') del[++ans]=i-1;
			if (a[i-2]=='t'&&a[i-1]=='w'&&a[i]=='o')
			if (a[i+1]=='o') del[++ans]=i-1;
						else del[++ans]=i,a[i]=0;
		}
		print(ans);
		for (int i=1;i<=ans;i++) print(del[i],' ');
		putchar('\n');
	}

	return 0;
}