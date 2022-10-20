#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int p=1e9+7;

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
void print(int x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
int h[N];

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read(),ans=0,sum=0;
	for (int i=1;i<=n;i++) h[i]=read()-1;
	for (int i=1;i<=n;i++)
	{
		ans=(ans+1LL*sum*min(h[i-1],h[i])%p+h[i])%p;
		sum=(1LL*sum*min(min(h[i-1],h[i+1]),h[i])%p+min(h[i],h[i+1]))%p;
	}
	print(ans);
	
	return 0;
}