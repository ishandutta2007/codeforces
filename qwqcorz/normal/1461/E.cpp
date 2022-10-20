#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+5;

ll read()
{
	ll s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(ll x)
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
void print(ll x,char c='\n')
{
	write(x);
	putchar(c);
}
bool f[N];

signed main()
{
	memset(f,0,sizeof(f));
	ll h=read(),l=read(),r=read(),k=read(),x=read(),y=read();
	h-=l;
	r-=l;
	l-=l;
	if (x>=y)
	{
		if (h+y<=r) h+=y;
		h-=x;
		k--;
		if ((k==0||(x-y)<=(double)h/k)&&h>=0) puts("Yes");
										 else puts("No");
		return 0;
	}
	bool flag=0;
	while (k>0)
	{
		k-=h/x;
		if (h/x==0&&flag) return puts("No"),0;
		flag=1;
		if (k<=0) break;
		h%=x;
		if (f[h]) break;
		f[h]=1;
		if (h+y>r) return puts("No"),0;
		h+=y;
	}
	puts("Yes");

	return 0;
}