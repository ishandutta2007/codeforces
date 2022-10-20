#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;

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
bool vis[N*2];
int a[N],up,n,k,r[N],val[N],st[N];
bool check(int d)
{
	int len=0,top=0;
	for (int i=1;i<=k;i++) if (d>>min(i-1,30)) len=i;
	val[n+1]=0;
	for (int i=n,now=0;i>=1;i--)
	{
		now|=a[i]<<min(len,n-i);
		if (n-i>=len) now=now>>1;
		val[i]=now;
	}
//	for (int i=1;i<=n;i++) print(val[i],' ');puts("");
	for (int i=1;i+k-1<=n;i++)
	if (r[i]>=k-len)
	if (val[i+k-len]<=d)
	if (!vis[val[i+k-len]])
	{
		st[++top]=val[i+k-len];
		vis[val[i+k-len]]=1;
	}
	int ret=top<=d;
	while (top) vis[st[top--]]=0;
	return ret;
}

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	int T=read();
	while (T--)
	{
		n=read(),k=read();
		for (int i=1;i<=n;i++)
		{
			char c=getchar();
			while (c!='0'&&c!='1') c=getchar();
			a[i]=!(c-'0');
		}
		r[n+1]=0;
		for (int i=n;i>=1;i--)
		if (a[i]) r[i]=0;
			 else r[i]=r[i+1]+1;
		int l=0,r=up=min(n,(1<<min(k,20))-1);
//		for (int i=l;i<=r;i++) print(i,':'),print(check(0));
		while (l<=r)
		{
			int mid=(l+r)/2;
			if (check(mid)) r=mid-1;
					   else l=mid+1;
		}
		if (l>up) puts("NO");
		else
		{
			puts("YES");
			for (int i=k-1;i>=0;i--) putchar('0'+((l>>min(i,30))&1));
			putchar('\n');
		}
	}
	
	return 0;
}