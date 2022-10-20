#include<bits/stdc++.h>
using namespace std;
const int N=8e5+5;

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
int l[N],r[N],b[N];
int c[N],a[N],one[N];

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	int T=read();
	while (T--)
	{
		int n=read(),cnt=0,ans=-1,atfirst=0,minl=1919810111,maxr=0;
		for (int i=1;i<=n;i++)
			b[++cnt]=l[i]=read(),
			b[++cnt]=r[i]=read();
		sort(b+1,b+1+cnt);
		cnt=unique(b+1,b+1+cnt)-b-1;
		for (int i=1;i<=n;i++)
			l[i]=lower_bound(b+1,b+1+cnt,l[i])-b,
			r[i]=lower_bound(b+1,b+1+cnt,r[i])-b;
		for (int i=1;i<=n;i++)
			l[i]=l[i]*2-1,
			r[i]=r[i]*2-1;
		for (int i=1;i<=n;i++)
			minl=min(minl,l[i]),
			maxr=max(maxr,r[i]);
		cnt=cnt*2+1;
		for (int i=1;i<=n;i++)
			c[l[i]]++,
			c[r[i]+1]--;
		for (int i=1;i<=cnt;i++) c[i]+=c[i-1];
		for (int i=1;i<=cnt;i++) if (c[i]==1&&c[i-1]>1) a[i]=1;
		for (int i=1;i<=cnt;i++) if (c[i]==1) one[i]=1;
		for (int i=1;i<=cnt;i++)
			one[i]+=one[i-1],
			a[i]+=a[i-1];
//		for (int i=0;i<=cnt;i++) putchar('0'+c[i]);puts("");
		for (int i=1;i<=cnt;i++) atfirst+=c[i]&&!c[i-1];
		for (int i=1;i<=n;i++)
		{
			int l=::l[i],r=::r[i];
			if (one[r]-one[l-1]==r-l+1)
			{
				int now=!!c[l-1]&&!!c[r+1];
				if (!c[l-1]&&!c[r+1]) now=-1;
				ans=max(ans,now);
				continue;
			}
			int now=a[r]-a[l-1];
			if (c[r]==1&&(!c[r+1]||r==maxr)) now--;
			if (c[l]==1&&c[l-1]&&l>minl) now++;
			ans=max(ans,now);
		}
		print(ans+atfirst);
		for (int i=1;i<=cnt;i++) c[i]=a[i]=one[i]=0;
	}
	
	return 0;
}