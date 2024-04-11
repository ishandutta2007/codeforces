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
int x[N],y[N];

signed main()
{
	int T=read();
	while (T--)
	{
		int n=read(),l=read(),r=read(),ans=0,cnt1=0,cnt2=0,need=0;
		for (int i=1;i<=l;i++) a[read()]++;
		for (int i=1;i<=r;i++) b[read()]++;
		for (int i=1;i<=n;i++)
		{
			int tmp=min(a[i],b[i]);
			a[i]-=tmp;
			b[i]-=tmp;
			if (a[i]) x[++cnt1]=a[i],need+=a[i];
			if (b[i]) y[++cnt2]=b[i],need-=b[i];
			a[i]=b[i]=0;
		}
		need/=2;
		if (need>0)
		for (int i=1;i<=cnt1;i++)
		{
			int tmp=min(need,x[i]/2);
			x[i]-=tmp*2;
			need-=tmp;
			ans+=tmp;
		}
		else
		for (int i=1;i<=cnt2;i++)
		{
			int tmp=min(-need,y[i]/2);
			y[i]-=tmp*2;
			need+=tmp;
			ans+=tmp;
		}
		ans+=abs(need);
		need=0;
		for (int i=1;i<=cnt1;i++) need+=x[i];
		for (int i=1;i<=cnt2;i++) need+=y[i];
		print(ans+need/2);
		for (int i=1;i<=n;i++) x[i]=y[i]=0;
	}
	return 0;
}