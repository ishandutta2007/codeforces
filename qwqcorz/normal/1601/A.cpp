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
int a[N],b[N];

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int T=read();
	while (T--)
	{
		int n=read();
		for (int i=1;i<=n;i++) a[i]=read();
		for (int i=1;i<=n;i++) b[i]=0;
		int tot=0;
		for (int j=0;j<30;j++)
		{
			int cnt=0;
			for (int i=1;i<=n;i++) cnt+=a[i]>>j&1;
			if (cnt) tot++,b[cnt]++;
		}
		for (int i=1;i<=n;i++)
		{
			int cnt=0;
			for (int j=i;j<=n;j+=i) cnt+=b[j];
			if (cnt==tot) print(i,' ');
		}
		puts("");
	}
	
	return 0;
}