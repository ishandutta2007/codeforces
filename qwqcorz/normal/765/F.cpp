#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
const int M=3e5+5;
const int inf=1e9+7;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

inline void ckmn(int &x,int y){if (x>y) x=y;}
inline void ckmx(int &x,int y){if (x<y) x=y;}
vector<pair<int,int>>q[N];
int a[N],ans[M],b[N];
struct segment_tree
{
	#define ls (w*2)
	#define rs (w*2+1)
	#define mid ((l+r)/2)
	int t[N*4],n;
	void send(int _n){n=_n;for (int i=1;i<=n*4;i++) t[i]=0;}
	void change(int w,int l,int r,int x,int y)
	{
		ckmx(t[w],y);
		if (l==r) return;
		if (x<=mid) change(ls,l,mid,x,y);
			   else change(rs,mid+1,r,x,y);
	}
	int query(int w,int l,int r,int ql,int qr)
	{
		if (qr<l||r<ql) return 0;
		if (ql<=l&&r<=qr) return t[w];
		return max(query(ls,l,mid,ql,qr),query(rs,mid+1,r,ql,qr));
	}
	void change(int x,int y)
	{
		int pos=lower_bound(b+1,b+1+n,x)-b;
		change(1,1,n,pos,y);
	}
	int query(int l,int r)
	{
		int L=lower_bound(b+1,b+1+n,l)-b;
		int R=upper_bound(b+1,b+1+n,r)-b-1;
		return query(1,1,n,L,R);
	}
	#undef mid
	#undef rs
	#undef ls
}t;
struct bit
{
	int t[N],n;
	void send(int _n){n=_n;for (int i=1;i<=n;i++) t[i]=inf;}
	void add(int x,int y){for (;x;x&=x-1) ckmn(t[x],y);}
	int query(int x){int ret=inf;for (;x<=n;x+=x&-x) ckmn(ret,t[x]);return ret;}
}mn;
void solve(int n)
{
	for (int i=1;i<=n;i++) b[i]=a[i];
	sort(b+1,b+1+n);
	int cnt=unique(b+1,b+1+n)-b-1;
	t.send(cnt);
	mn.send(n);
	int top=0;
	static int st[N]; st[0]=0;
	for (int i=1;i<=n;i++)
	{
		while (top&&a[st[top]]<a[i]) top--;
		int j=st[top];
		st[++top]=i;
		while (j)
		{
			mn.add(j,a[j]-a[i]);
			j=t.query(a[i],(a[i]+a[j]-1)/2);
		}
		t.change(a[i],i);
		for (auto j:q[i]) ckmn(ans[j.second],mn.query(j.first));
	}
	for (int i=1;i<=n;i++) a[i]=1e9-a[i];
}

signed main()
{
	memset(ans,0x3f,sizeof(ans));
	int n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	int Q=read();
	for (int i=1;i<=Q;i++)
	{
		int l=read(),r=read();
		q[r].push_back(make_pair(l,i));
	}
	solve(n);
	solve(n);
	for (int i=1;i<=Q;i++) print(ans[i]);
	
	return 0;
}