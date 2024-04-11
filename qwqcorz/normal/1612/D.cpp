#include<bits/stdc++.h>
#define int long long
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
bool check(int a,int b,int x)
{
	if (x>a||a==0) return 0;
	b=min(b,a-b);
	if (b==0) return x==a;
	return (a-x)%b==0||check(b,a%b,x);
}
bool GreenDay()
{
	int a=read(),b=read(),x=read();
	if (a<b) swap(a,b);
	return check(a,b,x);
}

signed main(signed Hello,char *CodeForces[])
{
	(void)Hello,(void)CodeForces;
//	int T=1;
	int T=read();
	while (T--) puts(GreenDay()?"YES":"NO");
	
	return 0;
}