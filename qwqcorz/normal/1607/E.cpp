#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

char a[N];
int solve(int n,int l,int r,int d,int len,int L,int R)
{
	l=-l;
	int i=d?(l+r+1>n?0:max((n-l-r-1)/abs(d),0)):0;
	int x=0,y=0;
	if (!i) x=1,y=n;
	   else x=l+1-min(d,0)*i,y=n-r-max(d,0)*i;
	int A=x,B=y;
	for (int i=1;i<=len;i++)
	{
//		print(x,','),print(y);
		if (x==y) return x;
		if (a[i]==L) A--,B--;
		if (a[i]==R) A++,B++;
		if (A==0) A++,x++;
		if (B>n) B--,y--;
	}
	return x;
}
void GreenDay()
{
	int n=read(),m=read();
	scanf("%s",a+1);
	int len=strlen(a+1);
	int lx=0,rx=0,x=0,ly=0,ry=0,y=0;
	for (int i=1;i<=len;i++)
	{
		if (a[i]=='L') lx=min(lx,--x);
		if (a[i]=='R') rx=max(rx,++x);
		if (a[i]=='U') ly=min(ly,--y);
		if (a[i]=='D') ry=max(ry,++y);
	}
	print(solve(n,ly,ry,y,len,'U','D'),' ');
	print(solve(m,lx,rx,x,len,'L','R'));
}

signed main()
{
//	int T=1;
	int T=read();
	while (T--) GreenDay();
	
	return 0;
}