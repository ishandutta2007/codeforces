#include<bits/stdc++.h>
#define ll long long
#define root rs[0]
using namespace std;
const int N=2e5+5;
const int M=1e6+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

vector<int>fac[N];
int p[N],np[N],st[N],top=0,ls[N],rs[N];
vector<pair<int,int>>L[N],R[N];
void dfs(int now,int l,int r)
{
	if (l>r) return;
	if (now-l<r-now)
	{
		int ri=r+1;
		for (int j:fac[p[now]])
		if (j*j!=p[now]&&np[j]>=now&&np[p[now]/j]>=now) ri=min(ri,max(np[j],np[p[now]/j]));
		for (int i=now;i>=l;i--)
		{
			if (p[now]%p[i]==0&&p[i]*p[i]!=p[now])
			{
				int pos=np[p[now]/p[i]];
				if (pos>=i) ri=min(ri,max(pos,now));
			}
			if (ri<=r) R[i].push_back({ri,r});
		}
	}
	else
	{
		int le=l-1;
		for (int j:fac[p[now]])
		if (j*j!=p[now]&&np[j]<=now&&np[p[now]/j]<=now) le=max(le,min(np[j],np[p[now]/j]));
		for (int i=now;i<=r;i++)
		{
			if (p[now]%p[i]==0&&p[i]*p[i]!=p[now])
			{
				int pos=np[p[now]/p[i]];
				if (pos<=i) le=max(le,min(pos,now));
			}
			if (l<=le) L[i].push_back({l,le});
		}
	}
	dfs(ls[now],l,now-1);
	dfs(rs[now],now+1,r);
}
ll ans[M];
vector<pair<int,int>>ql[N],qr[N];
struct segment_tree
{
	#define ls (w*2)
	#define rs (w*2+1)
	#define mid ((l+r)/2)
	struct node
	{
		ll sum,tag;
		node(){sum=tag=0;}
		node(ll x){sum=x,tag=0;}
		friend node operator +(node a,node b)
		{
			node ret;
			ret.sum=a.sum+b.sum;
			return ret;
		}
		void add(ll x,int l,int r)
		{
			sum+=(r-l+1)*x;
			tag+=x;
		}
	}t[N*4];
	void push_down(int w,int l,int r)
	{
		if (!t[w].tag) return;
		t[ls].add(t[w].tag,l,mid);
		t[rs].add(t[w].tag,mid+1,r);
		t[w].tag=0;
	}
	void add(int w,int l,int r,int ql,int qr,ll x)
	{
		if (ql<=l&&r<=qr) return t[w].add(x,l,r);
		push_down(w,l,r);
		if (ql<=mid) add(ls,l,mid,ql,qr,x);
		if (qr>mid) add(rs,mid+1,r,ql,qr,x);
		t[w]=t[ls]+t[rs];
	}
	ll query(int w,int l,int r,int ql,int qr)
	{
		if (ql<=l&&r<=qr) return t[w].sum;
		push_down(w,l,r);
		if (qr<=mid) return query(ls,l,mid,ql,qr);
		if (ql>mid) return query(rs,mid+1,r,ql,qr);
		return query(ls,l,mid,ql,qr)+query(rs,mid+1,r,ql,qr);
	}
	void build(int w,int l,int r)
	{
		if (l==r) return t[w]=node(),void();
		build(ls,l,mid);
		build(rs,mid+1,r);
		t[w]=t[ls]+t[rs];
	}
	#undef mid
	#undef rs
	#undef ls
}t;

signed main()
{
	int n=read(),Q=read();
	for (int i=1;i<=n;i++)
	for (int j=i;j<=n;j+=i) fac[j].push_back(i);
	p[n+1]=n+1;
	for (int i=1;i<=n;i++) np[p[i]=read()]=i;
	for (int i=1;i<=n+1;i++)
	{
		while (top&&p[st[top]]<p[i]) ls[i]=rs[st[top-1]]=st[top],top--;
		st[++top]=i;
	}
	dfs(root,1,n);
	for (int i=1;i<=Q;i++)
	{
		int l=read(),r=read();
		ql[r].push_back({l,i});
		qr[l].push_back({r,i});
	}
	for (int i=1;i<=n;i++)
	{
		for (auto [l,r]:L[i]) t.add(1,1,n,l,r,1);
		for (auto [l,id]:ql[i]) ans[id]=t.query(1,1,n,l,i);
	}
	t.build(1,1,n);
	for (int i=n;i>=1;i--)
	{//print(i,':'),print(l,' '),print(r),
		for (auto [l,r]:R[i]) t.add(1,1,n,l,r,1);
		for (auto [r,id]:qr[i]) ans[id]+=t.query(1,1,n,i,r);
	}
	for (int i=1;i<=Q;i++) print(ans[i]);
	
	return 0;
}