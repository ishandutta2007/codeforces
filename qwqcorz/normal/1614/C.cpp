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
int power(int a,int b)
{
	int ret=1;
	while (b)
	{
		if (b&1) ret=1LL*ret*a%p;
		a=1LL*a*a%p;
		b/=2;
	}
	return ret;
}
int c[N],l[N],r[N],x[N];
void GreenDay()
{
	int n=read(),m=read(),ans=0;
	for (int i=1;i<=m;i++) l[i]=read(),r[i]=read(),x[i]=read();
	for (int j=0;j<30;j++)
	{
		for (int i=1;i<=n;i++) c[i]=0;
		for (int i=1;i<=m;i++) if (~x[i]>>j&1) c[l[i]]++,c[r[i]+1]--;
		for (int i=1;i<=n;i++) c[i]+=c[i-1];
		bool flag=1;
		for (int i=1;i<=n;i++) flag&=!!c[i];
		if (flag) continue;
		ans=(ans+(1LL<<j)%p*power(2,n-1))%p;
	}
	print(ans);
}

signed main(signed Hello,char *CodeForces[])
{
	(void)Hello,(void)CodeForces;
//	int T=1;
	int T=read();
	while (T--) GreenDay();
	
	return 0;
}