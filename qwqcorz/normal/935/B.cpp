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
int a[N],sum[N];

signed main()
{
	int n=read(),ans=0;
	for (int i=1;i<=n;i++)
	{
		char c=getchar();
		while (c!='U'&&c!='R') c=getchar();
		if (c=='U') a[i]=1;
			   else a[i]=-1;
		sum[i]=sum[i-1]+a[i];
	}
	for (int i=1;i<n;i++)
	if (sum[i]==0&&a[i]==a[i+1])
	ans++;
	print(ans);

	return 0;
}