#include<bits/stdc++.h>
using namespace std;
const int N=35;

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
pair<int,int>a[N];

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int T=read();
	while (T--)
	{
		int n=read(),m=read(),cnt=0;
		for (int i=0;i<=30;i++)
		if (m>>i&1)
		{
			int x=(n^m^(1<<i))&~((1<<i)-1);
			a[++cnt]=make_pair(x,x+(1<<i)-1);
		}
		a[++cnt]=make_pair(n^m,n^m);
		sort(a+1,a+1+cnt);
//		for (int i=1;i<=cnt;i++) print(a[i].first,' '),print(a[i].second);
		if (a[1].first>0){puts("0");continue;}
		a[cnt+1]=make_pair((int)2e9,(int)2e9);
		for (int i=1,mx=0;i<=cnt;i++)
		{
			mx=max(mx,a[i].second);
			if (mx<a[i+1].first-1){print(mx+1);break;}
		}
	}
	
	return 0;
}