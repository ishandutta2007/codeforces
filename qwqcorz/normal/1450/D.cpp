#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;

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
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x<10) putchar(x+'0');
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
int a[N],q[N],h,t,b[N];
bool check(int n,int k)
{
	h=1;
	t=0;
	for (int i=1;i<=n;i++)
	{
		while (h<=t&&a[q[t]]>=a[i]) t--;
		q[++t]=i;
		while (h<=t&&i-q[h]+1>k) h++;
		if (i>=k) b[i-k+1]=a[q[h]];
	}
	sort(b+1,b+1+n-k+1);
//	print(k);
//	for (int i=1;i<=n-k+1;i++) print(b[i],' ');puts("");
	for (int i=1;i<=n-k+1;i++) if (b[i]!=i) return 0;
	return 1;
}

signed main()
{
	int T=read();
	while (T--)
	{
		int n=read();
		for (int i=1;i<=n;i++) a[i]=read();
		putchar(check(n,1)?'1':'0');
		int l=2,r=n;
		while (l<=r)
		{
			int mid=(l+r)/2;
			if (check(n,mid)) r=mid-1;
						 else l=mid+1;
		}
//		print(l);
		for (int i=2;i<=r;i++) putchar('0');
		for (int i=l;i<=n;i++) putchar('1');
		putchar('\n');
	}

	return 0;
}