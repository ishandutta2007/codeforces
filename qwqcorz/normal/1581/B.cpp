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
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
bool check(int n,int m,int k)
{
	if (k<0) return 0;
	if (k==0) return n==1&&m==0;
	if (k==1) return m==1LL*n*(n-1)/2;
	if (m<n-1||m>1LL*n*(n-1)/2) return 0;
	return 1;
}

signed main(signed bangumi,char *ss1672[])
{
	(void)bangumi,(void)ss1672;
	int T=read();
	while (T--)
	{
		int n=read(),m=read(),k=read()-2;
		puts(check(n,m,k)?"YES":"NO");
	}
	
	return 0;
}