#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;

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
int a[N];
int gcd(int x,int y){return !y?x:gcd(y,x%y);}
bool Multi_test_no_horses()
{
	int n=read(),k=read(),g=0;
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=2;i<=n;i++) g=gcd(g,a[i]-a[1]);
	return (k-a[1])%g==0;
}

signed main(signed Hello,char *CodeForces[])
{
	(void)Hello,(void)CodeForces;
//	int T=1;
	int T=read();
	while (T--) puts(Multi_test_no_horses()?"YES":"NO");
	
	return 0;
}