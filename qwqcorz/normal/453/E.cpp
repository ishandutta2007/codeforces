#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const int N=1e5+5;
const int LOG=20;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

struct hjtree
{
	#define mid ((l+r)/2)
	struct node
	{
		int sum,ls,rs;
	}t[N*LOG];
	int root[N],cnt=0;
	int add(int rt,int l,int r,int x,int y)
	{
		int w=++cnt;
		assert(cnt<N*LOG);
		t[w]=t[rt],t[w].sum+=y;
		if (l==r) return w;
		if (x<=mid) t[w].ls=add(t[rt].ls,l,mid,x,y);
			   else t[w].rs=add(t[rt].rs,mid+1,r,x,y);
		return w;
	}
	int query(int w,int l,int r,int ql,int qr)
	{
		if (!w) return 0;
		if (qr<l||r<ql) return 0;
		if (ql<=l&&r<=qr) return t[w].sum;
		return query(t[w].ls,l,mid,ql,qr)+query(t[w].rs,mid+1,r,ql,qr);
	}
	int query(int l,int r,int ql,int qr)
	{
		return query(root[r],0,N,ql,qr)-query(root[l-1],0,N,ql,qr);
	}
	#undef mid
}t1,t2;
int a[N],m[N],d[N];
map<int,int>mp;
void fix(int x)
{
	if (mp.count(x)) return;
	int col=prev(mp.lower_bound(x))->second;
	mp[x]=col;
}
int query(int l,int r,int now,int nxt)
{
	if (now<0) return min(a[l]+d[l]*nxt,m[l]);
	int t=min(nxt-now,(int)1e5);
	return t1.query(l,r,t,N)*t+t2.query(l,r,0,t-1);
}

signed main()
{
	int n=read();
	for (int i=1;i<=n;i++) a[i]=read(),m[i]=read(),d[i]=read();
	for (int i=1;i<=n+1;i++) mp[i]=-1;
	for (int i=1;i<=n;i++)
	{
		int t=d[i]?m[i]/d[i]:N;
		t1.root[i]=t1.add(t1.root[i-1],0,N,t,d[i]);
		t2.root[i]=t2.add(t2.root[i-1],0,N,t,m[i]);
	}
	int Q=read();
	while (Q--)
	{
		int t=read(),l=read(),r=read(),ans=0;
		fix(l),fix(r+1);
		auto now=mp.lower_bound(l),nxt=next(now);
		while (now->first<=r) ans+=query(now->first,nxt->first-1,now->second,t),now++,nxt++;
		now=mp.lower_bound(l);
		while ((nxt=next(now))->first<=r) mp.erase(nxt);
		mp[l]=t;
		print(ans);
	}
	
	return 0;
}