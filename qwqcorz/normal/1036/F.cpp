#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e6+5;

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
int a[N],cnt=0;

signed main()
{
	for (int i=2;i<=1e6;i++)
	for (int j=i*i*i;1;j*=i)
	{
		if ((int)sqrt(j)*(int)sqrt(j)!=j) a[++cnt]=j;
		if (j>1e18/i) break;
	}
	sort(a+1,a+1+cnt);
	cnt=unique(a+1,a+1+cnt)-a-1;
	int T=read();
	while (T--)
	{
		int n=read();
		int d=upper_bound(a+1,a+1+cnt,n)-a-1;
		print(n-d-(int)sqrt(n));
	}

	return 0;
}