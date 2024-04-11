#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;

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

signed main()
{
	int T=read();
	while (T--)
	{
		scanf("%s",a+1);
		int n=strlen(a+1),ans=0,A=0,B=0;
		for (int i=1;i<=n;i++)
		if (a[i]=='A') A++;
		else
		{
			if (A)
			{
				ans++;
				A--;
			}
			else if (B)
			{
				B=0;
				ans++;
			}
			else B++;
		}
		print(n-ans*2);
	}

	return 0;
}