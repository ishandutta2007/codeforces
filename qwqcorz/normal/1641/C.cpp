#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int fa[N],n,Q,m=0;
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int L[N],R[N],ans[N];
bool check(int l,int r);
struct segment_tree
{
	#define ls (w*2)
	#define rs (w*2+1)
	#define mid ((l+r)/2)
	int sum[N*4];
	vector<int>t[N*4];
	void add(int w,int l,int r,int x)
	{
		if (l==r) sum[w]++;
		else
		{
			if (x<=mid) add(ls,l,mid,x);
				   else add(rs,mid+1,r,x);
			sum[w]=sum[ls]+sum[rs];
		}
//		print(sum[w],':'),print(l,' '),print(r);
		if (sum[w]>=r-l) for (auto i:t[w]) check(L[i],R[i]);
	}
	void insert(int w,int l,int r,int ql,int qr,int x)
	{
		if (ql<=l&&r<=qr) return t[w].push_back(x),void();
		if (ql<=mid) insert(ls,l,mid,ql,qr,x);
		if (qr>mid) insert(rs,mid+1,r,ql,qr,x);
	}
	int query(int w,int l,int r,int ql,int qr)
	{
		if (qr<l||r<ql) return 0;
		if (ql<=l&&r<=qr) return sum[w];
		return query(ls,l,mid,ql,qr)+query(rs,mid+1,r,ql,qr);
	}
	#undef mid
	#undef rs
	#undef ls
}t;
bool check(int l,int r)
{
//	print(l,','),print(r,':'),print(t.query(1,1,n,l,r));
	if (t.query(1,1,n,l,r)==r-l)
	{
		int pos=find(l);
//		print(pos);
		if (pos>r) return 0;
		ans[pos]=1;
		fa[pos]=r+1;
		return 1;
	}
	return 0;
}
void GreenDay()
{
	memset(ans,-1,sizeof(ans));
	n=read(),Q=read();
	for (int i=1;i<=n+1;i++) fa[i]=i;
	while (Q--)
	{
		int opt=read();
		if (opt==0)
		{
			int l=read(),r=read(),x=read();
			if (x==0) for (int i=find(l);i<=r;i=find(i)) ans[i]=0,fa[i]=i+1,t.add(1,1,n,i);
			else if (!check(l,r)) L[++m]=l,R[m]=r,t.insert(1,1,n,l,r,m);
//			for (int i=1;i<=n;i++) print(fa[i]," \n"[i==n]);
		}
		else
		{
			int x=read();
			if (ans[x]==-1) puts("N/A");
			if (ans[x]==0) puts("NO");
			if (ans[x]==1) puts("YES");
		}
	}
}

signed main()
{
	int T=1;
//	int T=read();
	while (T--) GreenDay();
	
	return 0;
}