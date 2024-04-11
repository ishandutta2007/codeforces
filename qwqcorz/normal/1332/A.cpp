#include<bits/stdc++.h>
#define ll long long
using namespace std;

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

int main()
{
	ll t=read();
	while (t--)
	{
		ll l=read(),r=read(),d=read(),u=read(),x=read(),y=read(),x1=read(),Y1=read(),x2=read(),y2=read();
		if ((l||r)&&x1==x2) {puts("No");continue;}
		if ((u||d)&&Y1==y2) {puts("No");continue;}
		if (x2<x+r-l||x+r-l<x1) {puts("No");continue;}
		if (y2<y+u-d||y+u-d<Y1) {puts("No");continue;}
		puts("Yes");
	}

	return 0;
}