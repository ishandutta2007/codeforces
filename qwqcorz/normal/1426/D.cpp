#include<bits/stdc++.h>
#define int long long
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
map<int,bool>m;

signed main()
{
	m.clear();
	int n=read(),lsum=0,sum=0,ans=0;
	m[0]=1;
	for (int i=1;i<=n;i++)
	{
		int x=read();
		sum+=x;
		if (m[sum])
		{
			ans++;
			m.clear();
			m[lsum]=1;
		}
		m[sum]=1;
		lsum=sum;
	}
	print(ans);

	return 0;
}