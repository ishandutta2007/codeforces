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
bool Multi_test_no_horses()
{
	int n=read();
	for (int i=1;i<=n*2;i++) a[i]=read();
	sort(a+1,a+1+n*2);
	int sum=a[1];
	for (int i=1;i<=n;i++) if (a[i*2-1]!=a[i*2]) return 0;
	for (int i=1;i<n;i++) if (a[i*2]==a[i*2+1]) return 0;
	for (int i=1;i<=n;i++) if (a[i*2]%2) return 0;
	for (int i=1;i<n;i++) if ((a[i*2+1]-a[i*2])%(i*2)) return 0;
	for (int i=1;i<n;i++) sum-=(a[i*2+1]-a[i*2])/(i*2)*(n-i)*2;
	return sum>=n*2&&sum%(n*2)==0;
}

signed main(signed Hello,char *CodeForces[])
{
	(void)Hello,(void)CodeForces;
//	int T=1;
	int T=read();
	while (T--) puts(Multi_test_no_horses()?"YES":"NO");
	
	return 0;
}