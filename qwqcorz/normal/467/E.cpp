#include<bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
const int N=5e5+5;

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
struct segment_tree
{
	#define ls (w*2)
	#define rs (w*2+1)
	#define mid ((l+r)/2)
	int t[N*4];
	void change(int w,int l,int r,int x,int y)
	{
		t[w]=max(t[w],y);
		if (l==r) return;
		if (x<=mid) change(ls,l,mid,x,y);
			   else change(rs,mid+1,r,x,y);
	}
	int query(int w,int l,int r,int ql,int qr)
	{
		if (r<ql||qr<l) return 0;
		if (ql<=l&&r<=qr) return t[w];
		return max(query(ls,l,mid,ql,qr),query(rs,mid+1,r,ql,qr));
	}
	#undef ls
	#undef rs
	#undef mid
}t;
struct Query
{
	int l,r,id;
	bool operator <(const Query &a)const
	{
		return l<a.l;
	}
}q[N*2];
int ans[N*2],cnt=0,nxt[N];
map<int,vector<int> >pre;
int a[N],dp[N],val[N],from[N],trans[N];
vector<int>tr[N];
void output(int x)
{
	if (!x) return;
	output(from[x]);
	if (val[x])
	{
		print(val[x],' ');
		print(a[x],' ');
		print(val[x],' ');
		print(a[x],' ');
	}
}

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	int n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++)
	{
		if (pre.count(a[i]))
		{
			nxt[pre[a[i]].back()]=i;
			if ((int)pre[a[i]].size()>=3) trans[i]=pre[a[i]][(int)pre[a[i]].size()-3];
			for (int j=1;j<=min((int)pre[a[i]].size(),2);j++)
			{
				cnt++;
				q[cnt]=(Query){pre[a[i]][(int)pre[a[i]].size()-j],i,cnt};
				tr[i].push_back(cnt);
			}
		}
		pre[a[i]].push_back(i);
	}
	sort(q+1,q+1+cnt);
	for (int i=1,j=1;i<=cnt;i++)
	{
		while (j<=n&&j<q[i].l)
		{
			if (nxt[j]) t.change(1,1,n,nxt[j],j);
			j++;
		}
		ans[q[i].id]=t.query(1,1,n,q[i].l+1,q[i].r);
	}
	for (int i=1;i<=n;i++)
	{
		dp[i]=dp[i-1];
		from[i]=i-1;
		val[i]=0;
		if (trans[i]&&dp[i]<dp[trans[i]-1]+1)
		{
			dp[i]=dp[trans[i]-1]+1;
			from[i]=trans[i]-1;
			val[i]=a[i];
		}
		for (int j:tr[i])
		if (ans[j]&&dp[i]<dp[ans[j]-1]+1)
		{
			dp[i]=dp[ans[j]-1]+1;
			from[i]=ans[j]-1;
			val[i]=a[ans[j]];
		}
	}
	print(dp[n]*4);
	output(n);
	
	return 0;
}