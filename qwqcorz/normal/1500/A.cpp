#include<bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
const int N=2e5+5;
const int M=5e6+5;

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
pair<int,int>b[M];

signed main()
{
	int n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++)
	for (int j=i+1;j<=n;j++)
	{
		int sum=a[i]+a[j];
		if (b[sum].fi)
		{
			if (b[sum].fi!=i&&b[sum].se!=i&&b[sum].fi!=j&&b[sum].se!=j)
			{
				puts("YES");
				print(i,' ');
				print(j,' ');
				print(b[sum].fi,' ');
				print(b[sum].se);
				return 0;
			}
		}
		else b[sum]=mk(i,j);
	}
	puts("NO");

	return 0;
}