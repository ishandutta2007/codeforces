#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
const int inf=1e9;

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
struct sgt
{
	#define ls (w*2)
	#define rs (w*2+1)
	#define mid (l+r)/2
	struct node
	{
		pair<int,int>mx,tag;
		void update(pair<int,int>x)
		{
			mx=max(mx,x);
			tag=max(tag,x);
		}
	}t[N*8];
	void push_down(int w)
	{
		if (!t[w].tag.first) return;
		t[ls].update(t[w].tag);
		t[rs].update(t[w].tag);
		t[w].tag=make_pair(0,0);
	}
	void change(int w,int l,int r,int ql,int qr,pair<int,int>x)
	{
		if (qr<l||r<ql) return;
		if (ql<=l&&r<=qr) return t[w].update(x);
		push_down(w);
		change(ls,l,mid,ql,qr,x);
		change(rs,mid+1,r,ql,qr,x);
		t[w].mx=max(t[ls].mx,t[rs].mx);
	}
	pair<int,int>query(int w,int l,int r,int ql,int qr)
	{
		if (qr<l||r<ql) return make_pair(0,0);
		if (ql<=l&&r<=qr) return t[w].mx;
		push_down(w);
		return max(query(ls,l,mid,ql,qr),query(rs,mid+1,r,ql,qr));
	}
	#undef mid
	#undef rs
	#undef ls
}t;
vector<int>id[N];
struct zyk
{
	int x,l,r;
}a[N];
int dp[N],from[N],b[N*2];
bool vis[N];
void get(int now)
{
	vis[a[now].x]=1;
	if (a[now].x) get(from[now]);
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read(),m=read(),cnt=0;
	for (int i=1;i<=m;i++) a[i].x=read(),b[++cnt]=a[i].l=read(),b[++cnt]=a[i].r=read()+1;
	sort(b+1,b+1+cnt);
	cnt=unique(b+1,b+1+cnt)-b-1;
	for (int i=1;i<=m;i++)
		a[i].l=lower_bound(b+1,b+1+cnt,a[i].l)-b,
		a[i].r=lower_bound(b+1,b+1+cnt,a[i].r)-b;
	a[m+1]=(zyk){0,1,cnt};
	a[m+=2]=(zyk){n+1,1,cnt};
	for (int i=1;i<=m;i++) id[a[i].x].push_back(i);
	for (int i=0;i<=n+1;i++)
	{
		pair<int,int>mx;
		for (int j:id[i]) mx=max(mx,t.query(1,1,cnt,a[j].l,a[j].r-1));
		for (int j:id[i]) dp[j]=mx.first+1,from[j]=mx.second;
		for (int j:id[i]) t.change(1,1,cnt,a[j].l,a[j].r-1,make_pair(dp[j],j));
	}
	get(m);
	vector<int>ans;
	for (int i=1;i<=n;i++) if (!vis[i]) ans.push_back(i);
	print(ans.size());
	for (int i:ans) print(i,' ');
	
	return 0;
}