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
int a[N];
bool check(int n)
{
	for (int i=2;i*i<=n;i++)
	if (n%i==0) return 0;
	return 1;
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int T=read();
	while (T--)
	{
		int n=read(),sum=0;
		for (int i=1;i<=n;i++) sum+=a[i]=read();
		if (!check(sum))
		{
			print(n);
			for (int i=1;i<=n;i++) print(i," \n"[i==n]);
		}
		else
		{
			int pos=0;
			for (int i=1;i<=n;i++) if (a[i]&1) pos=i;
			print(n-1);
			for (int i=1;i<=n;i++) if (i!=pos) print(i,' ');
			puts("");
		}
	}
	
	return 0;
}