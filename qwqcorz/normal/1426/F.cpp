#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
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
void add(int &x,int y)
{
	x+=y;
	if (x>=p) x-=p;
}
int power(int a,int b)
{
	int ret=1;
	while (b)
	{
		if (b&1) ret=ret*a%p;
		a=a*a%p;
		b/=2;
	}
	return ret;
}
char a[N];
int c=0,bc=0,x=0,bx=0,xc=0,xx=0;

signed main()
{
	int n=read(),ans=0,cnt=0;
	scanf("%s",a+1);
	for (int i=1;i<=n;i++) cnt+=a[i]=='?';
	for (int i=n;i>=1;i--)
	{
		if (a[i]=='a') add(ans,(bx*power(3,cnt-1)%p+xc*power(3,cnt-1)%p+xx*power(3,cnt-2)%p+bc*power(3,cnt)%p)%p);
		if (a[i]=='?') add(ans,(bx*power(3,cnt-2)%p+xc*power(3,cnt-2)%p+xx*power(3,cnt-3)%p+bc*power(3,cnt-1)%p)%p);
		if (a[i]=='b')
		{
			add(bc,c);
			add(bx,x);
		}
		if (a[i]=='c') add(c,1);
		if (a[i]=='?')
		{
			add(xc,c);
			add(xx,x);
			add(x,1);
		}
	}
	print(ans);

	return 0;
}