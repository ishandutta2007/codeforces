#include<bits/stdc++.h>
using namespace std;
const int N=105;

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
int all(int n)
{
	int ret=0;
	for (int i=0;i<=n%4;i++) ret^=n-i;
	return ret;
}
void GunRose()
{
	int a=read(),b=read();
	if (all(a-1)==b) return print(a);
	print(a+1+(all(a)==b));
}

signed main()
{
	int T=read();
	while (T--) GunRose();
	
	return 0;
}