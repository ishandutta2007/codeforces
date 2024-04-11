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
int solve(int a,int n,int p)
{
	if (1LL*a*n<p) return max(a,p-a*n);
	int nxt=1LL*a*n/p-(1LL*a*n%p<1LL*a*(p/a-1));
	return solve(p%a,nxt,a);
}

signed main()
{
	int T=read();
	while (T--)
	{
		int a=read(),n=read(),p=read(),d=read();a%=p;
		puts(a<=d||(1LL*a*n>=p&&solve(a,n,p)<=d)?"YES":"NO");
	}
	
	return 0;
}