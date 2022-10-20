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
bool check(int n,int k)
{
	int now=0;
	for (int i=1;i<=n;i++)
	if (a[i]>=k-now-1&&b[i]>=now)
	if (++now>=k) return 1;
	return 0;
}
void GreenDay()
{
	int n=read();
	for (int i=1;i<=n;i++) a[i]=read(),b[i]=read();
	int l=1,r=n;
	while (l<=r)
	{
		int mid=(l+r)/2;
		if (check(n,mid)) l=mid+1;
					 else r=mid-1;
	}
	print(r);
}

signed main(signed Hello,char *CodeForces[])
{
	(void)Hello,(void)CodeForces;
//	int T=1;
	int T=read();
	while (T--) GreenDay();
	
	return 0;
}