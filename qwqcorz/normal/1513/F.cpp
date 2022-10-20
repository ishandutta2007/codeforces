#include<bits/stdc++.h>
#define ll long long
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
void write(ll x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(ll x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
ll ans=0;
int x[N],y[N],p[N];
struct node
{
	int l,r;
	bool operator <(const node &a)const
	{
		return l<a.l;
	}
}a[N],b[N];

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	int n=read(),cnt1=0,cnt2=0,Max=0;
	for (int i=1;i<=n;i++) x[i]=read();
	for (int i=1;i<=n;i++) y[i]=read();
	for (int i=1;i<=n;i++) ans+=abs(x[i]-y[i]);
	for (int i=1;i<=n;i++)
	if (x[i]>y[i]) a[++cnt1]=(node){p[i]=y[i],x[i]};
			  else b[++cnt2]=(node){p[i]=x[i],y[i]};
	sort(p+1,p+1+n);
	sort(a+1,a+1+cnt1);
	sort(b+1,b+1+cnt2);
	for (int i=1,j=1,k=1,r1=0,r2=0;i<=n;i++)
	{
		while (j<=cnt1&&a[j].l<=p[i]) r1=max(r1,a[j++].r);
		while (k<=cnt2&&b[k].l<=p[i]) r2=max(r2,b[k++].r);
		Max=max(Max,min(r1,r2)-p[i]);
	}
	print(ans-Max*2);
	
	return 0;
}