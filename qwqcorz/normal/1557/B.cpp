#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;

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

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int T=read();
	while (T--)
	{
		int n=read(),k=read(),zyk=n;
		for (int i=1;i<=n;i++) b[i]=a[i]=read();
		sort(b+1,b+1+n);
		int cnt=unique(b+1,b+1+n)-b-1;
		for (int i=1;i<=n;i++) a[i]=lower_bound(b+1,b+1+cnt,a[i])-b;
		for (int i=1;i<n;i++) if (a[i]+1==a[i+1]) zyk--;
		puts(zyk<=k?"Yes":"No");
	}
	
	return 0;
}