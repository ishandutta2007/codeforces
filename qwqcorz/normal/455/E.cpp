#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
using namespace std;
const int N=1e5+5;
const ll inf=1LL<<60;

static const int IN_BUF = 1 << 23, OUT_BUF = 1 << 23;
inline char myGetchar() {
	static char buf[IN_BUF], *ps = buf, *pt = buf;
	if (ps == pt) {
		ps = buf, pt = buf + fread(buf, 1, IN_BUF, stdin);
	}
	return ps == pt ? EOF : *ps++;
}
inline void myPutchar(char x) {
	static char pbuf[OUT_BUF], *pp = pbuf;
	struct _flusher {
		~_flusher() {
			fwrite(pbuf, 1, pp - pbuf, stdout);
		}
	};
	static _flusher outputFlusher;
	if (pp == pbuf + OUT_BUF) {
		fwrite(pbuf, 1, OUT_BUF, stdout);
		pp = pbuf;
	}
	*pp++ = x;
}
int read()
{
	int s=0;
	char c=myGetchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=myGetchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=myGetchar();
	return lc=='-'?-s:s;
}
void write(ll x)
{
	if (x<0)
	{
		myPutchar('-');
		x=-x;
	}
	if (x<10) myPutchar(x+'0');
	else
	{
		write(x/10);
		myPutchar(x%10+'0');
	}
}
void print(ll x,char c='\n')
{
	write(x);
	myPutchar(c);
}
struct LiChao_Tree
{
	#define mid ((l+r)/2)
	pair<int,int>st[N*30];
	int top,cntl;
	ll k[N],b[N];
	struct node
	{
		int v,ls,rs;
	}t[N*30];
	int cntn,root;
	bool cmp(int u,int v,int x)
	{
		return k[u]*x+b[u]<k[v]*x+b[v];
	}
	void insert(int &w,int l,int r,int x)
	{
		if (!w) w=++cntn;
		if (!t[w].v) return st[++top]=mk(w,0),t[w].v=x,void();
		if (cmp(x,t[w].v,mid)) st[++top]=mk(w,t[w].v),swap(t[w].v,x);
		if (l==r) return;
		if (cmp(x,t[w].v,l)) insert(t[w].ls,l,mid,x);
		if (cmp(x,t[w].v,r)) insert(t[w].rs,mid+1,r,x);
	}
	void insert(ll _k,ll _b)
	{
		cntl++;
		k[cntl]=_k;
		b[cntl]=_b;
		insert(root,-5e5,1e9,cntl);
	}
	ll query(int w,int l,int r,int x)
	{
		if (!w) return inf;
		ll ret=t[w].v?k[t[w].v]*x+b[t[w].v]:inf;
		if (l==r) return ret;
		if (x<=mid) return min(ret,query(t[w].ls,l,mid,x));
			   else return min(ret,query(t[w].rs,mid+1,r,x));
	}
	void pop(int x)
	{
		while (top>x) t[st[top].fi].v=st[top].se,top--;
	}
	#undef mid
}t;
vector<pair<int,int> >q[N];
int st[N],top=0,Top[N];
ll a[N],ans[N],sum[N];

signed main()
{
	int n=read();
	for (int i=1;i<=n;i++) sum[i]=sum[i-1]+(a[i]=read());
	int Q=read();
	for (int i=1;i<=Q;i++)
	{
		int x=read(),y=read();
		q[y].push_back(mk(x,i));
	}
	for (int i=1;i<=n;i++)
	{
		while (top&&a[st[top]]>=a[i]) top--;
		t.pop(Top[top]);
		st[++top]=i;
		t.insert(a[i],a[i]*i-sum[i]);
		Top[top]=t.top;
		for (auto j:q[i])
		{
			int x=j.fi;
			ans[j.se]=t.query(t.root,-5e5,1e9,x-i)+sum[i];
		}
	}
	for (int i=1;i<=Q;i++) print(ans[i]);
	
	return 0;
}