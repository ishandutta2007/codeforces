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
char a[N],b[N];

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int T=read();
	while (T--)
	{
		int n=read(),ans=0;
		scanf("%s%s",a+1,b+1);
		for (int i=1;i<=n;i++) if (a[i]!=b[i]) ans+=2,a[i]='2';
		for (int i=1;i<=n;i++) if (a[i]=='0') ans++;
		for (int i=1;i<n;i++) if (a[i]<'2'&&a[i+1]<'2'&&a[i]!=a[i+1]) ans++,a[i]=a[i+1]='2';
		print(ans);
	}
	
	return 0;
}