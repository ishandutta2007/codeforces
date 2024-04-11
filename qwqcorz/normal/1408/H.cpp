#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

struct segment_tree
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
		if (ql<=l&&r<=qr) return update(w,x);
		push_down(w);
		if (ql<=mid) add(ls,l,mid,ql,qr,x);
		if (qr>mid) add(rs,mid+1,r,ql,qr,x);
		t[w]=min(t[ls],t[rs]);
	}
	void build(int w,int l,int r)
	{
		tag[w]=0;
		if (l==r) return t[w]=l,void();
		build(ls,l,mid);
		build(rs,mid+1,r);
		t[w]=min(t[ls],t[rs]);
	}
	#undef mid
	#undef rs
	#undef ls
}t;
int a[N];
vector<int>b[N],k[N];
void Queen()
{
	int n=read(),m=0;
	for (int i=1;i<=n;i++) a[i]=read(),m+=!a[i];
	int mid=m/2;
	if (!mid) return puts("0"),void();
	for (int i=0;i<=n;i++) b[i].clear(),k[i].clear();
	for (int i=1;i<=n;i++) b[a[i]].push_back(i);
	int L=b[0][mid-1],R=b[0][m-mid],ans=mid;
	t.build(1,0,mid);
	for (int i=1;i<=n;i++)
	if (!b[i].empty())
	{
		int l=0,r=0;
		for (int j:b[i]) if (j<R) l=max(l,int(lower_bound(b[0].begin(),b[0].end(),j)-b[0].begin()));
		for (int j:b[i]) if (j>L) r=max(r,int(b[0].end()-lower_bound(b[0].begin(),b[0].end(),j)));
		l=min(l,mid),r=min(r,mid);
		k[l].push_back(r);
		if (r) t.add(1,0,mid,0,r-1,1);
	}
	for (int i=mid;i>=0;i--)
	{
		ans=min(ans,t.t[1]+i);
		for (int j:k[i]) t.add(1,0,mid,j,mid,1);
	}
	print(ans);
}

signed main()
{
	int T=read();
	while (T--) Queen();
	
	return 0;
}