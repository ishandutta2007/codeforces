#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int p=1e9+7;
const int inv2=(p+1)/2;

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
int fact[N];
void ysgs(int n)
{
	for (int i=fact[0]=1;i<=n;i++) fact[i]=1LL*fact[i-1]*i%p;
}

signed main(signed bangumi,char *ss1672[])
{
	(void)bangumi,(void)ss1672;
	ysgs(2e5);
	int T=read();
	while (T--)
	{
		int n=read();
		print(1LL*fact[n*2]*inv2%p);
	}
	
	return 0;
}