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
void print(int x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
int a[N*2],b[N*2],ans=N,t;

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	int n=read(),h=read(),m=read(),k=read();
	for (int i=1;i<=n;i++)
	{
		int hh=read(),mm=read();
		a[i]=b[i]=mm%(m/2);
		(void)hh,(void)h;
	}
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++) a[i+n]=a[i]+m/2;
	for (int i=1;i<=n;i++) b[i+n]=b[i]+m/2;
	for (int i=1,j=1;i<=n;i++)
	{
		while (a[j]<a[i]+k) j++;
		if (j-i-1<ans) ans=j-i-1,t=i;
	}
	print(ans,' ');
	print((a[t]+k)%(m/2));
	for (int i=1;i<=n*2;i++) if (a[t]<b[i]&&b[i]<a[t]+k) print((i-1)%n+1,' ');
	puts("");
	
	return 0;
}