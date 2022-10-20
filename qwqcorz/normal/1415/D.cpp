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
int a[N];

signed main()
{
	int n=read(),ans=n;
	if (n>100) puts("1");
	else 
	{
		for (int i=1;i<=n;i++) a[i]=read();
		for (int i=1;i<=n;i++)
		for (int j=i,s1=a[i];j<=n;s1^=a[++j])
		for (int k=j+1,s2=a[k];k<=n;s2^=a[++k])
		if (s1>s2) ans=min(ans,j-i+k-j-1);
		print(ans<n?ans:-1);
	}

	return 0;
}