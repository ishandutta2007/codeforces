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
bool prime(int n)
{
	for (int i=2;i*i<=n;i++)
	if (n%i==0) return 0;
	return 1;
}
void check(int n)
{
	int m=n;
	if (n==1) puts("FastestFinger");
	else if (n==2) puts("Ashishgup");
	else if (n&1) puts("Ashishgup");
	else
	{
		int cnt=0;
		while (n%2==0) cnt++,n/=2;
		if (n>1)
		{
			if (cnt>1) puts("Ashishgup");
			else if (prime(n)) puts("FastestFinger");
			else puts("Ashishgup");
		}
		else puts("FastestFinger");
	}
}

int main()
{
	int T=read();
	while (T--)
	{
		int n=read();
		check(n);
	}

	return 0;
}