#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;

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
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
struct basis
{
	int val[21],pos[21];
	void insert(int x,int y)
	{
		for (int i=20;i>=0;i--)
		if (y>>i&1)
		{
			if (x>pos[i])
				swap(pos[i],x),
				swap(val[i],y);
			y^=val[i];
		}
	}
	int query(int l)
	{
		int ret=0;
		for (int i=20;i>=0;i--) if (pos[i]>=l&&(ret>>i&1)==0) ret^=val[i];
		return ret;
	}
}b[N];
int a[N];

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) (b[i]=b[i-1]).insert(i,a[i]);
	int m=read();
	while (m--)
	{
		int l=read(),r=read();
		print(b[r].query(l));
	}
	
	return 0;
}