#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
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
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
int a[N];
int gcd(int x,int y){return !y?x:gcd(y,x%y);}
int lcm(int x,int y){return x/gcd(x,y)*y;}
bool Multi_test_no_horses()
{
	int n=read(),t=1;
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++)
	{
		t=min(lcm(t,i+1),p);
		if (a[i]%t==0) return 0;
	}
	return 1;
}

signed main(signed Hello,char *CodeForces[])
{
	(void)Hello,(void)CodeForces;
//	int T=1;
	int T=read();
	while (T--) puts(Multi_test_no_horses()?"YES":"NO");
	
	return 0;
}