#include<bits/stdc++.h>
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
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
int pw[N],a[N];
void GreenDay()
{
	int n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=pw[0]=1;i<=n;i++) pw[i]=pw[i-1]*2%p;
	int tot=0;
	for (int i=1;i<=n;i++) if (a[i]%2==0) tot++;
	int ans=(pw[n]-pw[tot]+p)%p;
	for (int j=2;j<=1e9;j*=2)
	{
		int tot=0,tot1=0;
		for (int i=1;i<=n;i++) if (a[i]%j==0) tot++,tot1+=(a[i]/j)&1;
		if (tot1) ans=(ans+1LL*pw[tot-tot1]*(pw[tot1-1]-1))%p;
	}
	print(ans);
}

signed main(signed Hello,char *CodeForces[])
{
	(void)Hello,(void)CodeForces;
	int T=1;
//	int T=read();
	while (T--) GreenDay();
	
	return 0;
}