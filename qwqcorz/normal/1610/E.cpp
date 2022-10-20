#include<bits/stdc++.h>
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
int a[N],nxt[N];
void GreenDay()
{
	int n=read(),ans=0;
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=n;i>=1;i--) nxt[i]=i<n&&a[i]==a[i+1]?nxt[i+1]:i;
	for (int i=1;i<=n;i++)
	if (a[i]!=a[i-1])
	{
		int x=a[i],tot=nxt[i]-i+1,now=nxt[i];
		while (1)
		{
			int nxt=lower_bound(a+now+1,a+n+1,a[now]*2-x)-a;
			if (nxt>n) break;
			tot++,now=nxt;
		}
		ans=max(ans,tot);
	}
	print(n-ans);
}

signed main(signed Hello,char *CodeForces[])
{
	(void)Hello,(void)CodeForces;
//	int T=1;
	int T=read();
	while (T--) GreenDay();
	
	return 0;
}