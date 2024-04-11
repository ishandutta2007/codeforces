#include<bits/stdc++.h>
using namespace std;
const int N=305;

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
int a[N],p[N];

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int T=read();
	while (T--)
	{
		int n=read(),m=read(),ans=0;
		for (int i=1;i<=m;i++) a[i]=read();
		for (int i=1;i<=m;i++) p[i]=i;
		sort(p+1,p+1+m,[&](int x,int y){return a[x]!=a[y]?a[x]<a[y]:x>y;});
		for (int i=1;i<=m;i++)
		for (int j=i+1;j<=m;j++) ans+=p[i]<p[j];
		print(ans);
	}
	
	return 0;
}