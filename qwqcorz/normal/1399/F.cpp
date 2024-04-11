#include<bits/stdc++.h>
using namespace std;
const int N=3e3+5;

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
int f[N],g[N],l[N],b[N*2],n,cnt;
struct node
{
	int l,r;
	bool operator <(const node &a)const
	{
		return r==a.r?r-l<a.r-a.l:r<a.r;
	}
}a[N];

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	int T=read();
	while (T--)
	{
		n=read(),cnt=0;
		for (int i=1;i<=n;i++)
			b[++cnt]=a[i].l=read(),
			b[++cnt]=a[i].r=read();
		sort(b+1,b+1+cnt);
		cnt=unique(b+1,b+1+cnt)-b-1;
		for (int i=1;i<=n;i++)
			a[i].l=lower_bound(b+1,b+1+cnt,a[i].l)-b,
			a[i].r=lower_bound(b+1,b+1+cnt,a[i].r)-b;
		a[++n]=(node){1,cnt};
		sort(a+1,a+1+n);
		for (int i=1;i<=n;i++)
		{
			l[i]=lower_bound(a+1,a+1+i,a[i].l,[&](const node &a,const int &b){return a.r<b;})-a-1;
			f[i]=1;
			for (int j=1;j<i;j++)
			{
				g[j]=0;
				if (a[i].l<=a[j].l)
				{
					g[j]=g[l[j]]+f[j];
					f[i]=max(f[i],g[j]+1);
				}
				g[j]=max(g[j],g[j-1]);
			}
		}
		print(f[n]-1);
	}
	
	return 0;
}