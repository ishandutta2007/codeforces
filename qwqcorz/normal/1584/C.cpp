#include<bits/stdc++.h>
using namespace std;
const int N=105;

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
int a[N],b[N]; 
bool Multi_test_no_horses()
{
	int n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) b[i]=read();
	sort(a+1,a+1+n),sort(b+1,b+1+n);
	for (int i=1;i<=n;i++) a[i]=b[i]-a[i];
	for (int i=1;i<=n;i++) if (a[i]<0||a[i]>1) return 0;
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