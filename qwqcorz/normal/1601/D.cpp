#include<bits/stdc++.h>
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
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
struct segment
{
	#define ls (w*2)
	#define rs (w*2+1)
	#define mid ((l+r)/2)
	int t[N*4],tag[N*4];
	void update(int w,int x)
	{
		t[w]+=x;
		tag[w]+=x;
	}
	void push_down(int w)
	{
		if (!tag[w]) return;
		update(ls,tag[w]);
		update(rs,tag[w]);
		tag[w]=0;
	}
	void add(int w,int l,int r,int ql,int qr,int x)
	{
		if (qr<l||r<ql) return;
		if (ql<=l&&r<=qr) return update(w,x);
		push_down(w);
		add(ls,l,mid,ql,qr,x);
		add(rs,mid+1,r,ql,qr,x);
		t[w]=max(t[ls],t[rs]);
	}
	int query(int w,int l,int r,int ql,int qr)
	{
		if (ql<=l&&r<=qr) return t[w];
		push_down(w);
		if (qr<=mid) return query(ls,l,mid,ql,qr);
		if (ql>mid) return query(rs,mid+1,r,ql,qr);
		return max(query(ls,l,mid,ql,qr),query(rs,mid+1,r,ql,qr));
	}
	#undef mid
	#undef rs
	#undef ls
}t;
struct node
{
	int s,a;
	bool operator <(const node &x)const
	{
		return a<x.a;
	}
}a[N];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
int dp[N];

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read(),d=read(),ans=0;
	for (int i=1;i<=n;i++)
		a[i].s=read(),
		a[i].a=read();
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++)
	{
		while (!q.empty()&&q.top().first<max(a[i].a,d)) t.add(1,0,n,0,q.top().second-1,-1),q.pop();
		int pos=upper_bound(a+1,a+i,(node){0,a[i].s})-a-1;
		if (a[i].s>=d&&pos>=0) t.add(1,0,n,i,i,dp[i]=t.query(1,0,n,0,pos)+1);
		ans=max(ans,dp[i]);
		q.push(make_pair(a[i].s,i));
		t.add(1,0,n,0,i-1,1);
	}
	print(ans);
	
	return 0;
}