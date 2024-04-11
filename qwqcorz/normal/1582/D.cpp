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
int a[N];

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int T=read();
	while (T--)
	{
		int n=read();
		for (int i=1;i<=n;i++) a[i]=read();
		if (n%2==0)
		for (int i=1;i<=n;i+=2)
		{
			print(a[i+1],' ');
			print(-a[i]," \n"[i+1==n]);
		}
		else
		{
			for (int i=1;i+3<=n;i+=2)
			{
				print(a[i+1],' ');
				print(-a[i],' ');
			}
			int p[3]={0,1,2},ans[3];
			do
			{
				if (a[n-p[0]]+a[n-p[1]])
				{
					ans[p[2]]=a[n-p[0]]+a[n-p[1]];
					ans[p[1]]=-a[n-p[2]];
					ans[p[0]]=-a[n-p[2]];
					break;
				}
			}while (next_permutation(p,p+3));
			print(ans[2],' ');
			print(ans[1],' ');
			print(ans[0]);
		}
	} 
	
	return 0;
}