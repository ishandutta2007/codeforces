#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;

ll read()
{
	ll s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(ll x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(ll x,char c='\n')
{
	write(x);
	putchar(c);
}
struct segment_tree
{
	#define ls (w*2)
	#define rs (w*2+1)
	#define mid ((l+r)/2)
	int t[N*4][3],tag[N*4];
	void update(int w,int x)
	{
		int nxt[3]={};
		for (int i=0;i<3;i++) if (i+x>=0&&i+x<3) nxt[i+x]=t[w][i];
		memcpy(t[w],nxt,sizeof(int)*3);
		tag[w]+=x;
	}
	void push_up(int w)
	{
		for (int i=0;i<3;i++) t[w][i]=t[ls][i]+t[rs][i];
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
		push_up(w);
	}
	void build(int w,int l,int r)
	{
		if (l==r) return void(t[w][0]=1);
		build(ls,l,mid);
		build(rs,mid+1,r);
		push_up(w);
	}
	#undef mid
	#undef rs
	#undef ls
}t;
struct node
{
	int x,l,r,v;
	bool operator <(const node &a)const
	{
		return x<a.x||(x==a.x&&v<a.v);
	}
};
ll a[N];
int l1[N],r1[N],l2[N],r2[N],st[N],top;
void GreenDay()
{
	ll ans=0;
	int n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	st[top=0]=0;
	for (int i=1;i<=n;i++)
	{
		while (top&&a[st[top]]>=a[i]) top--;
		l1[i]=st[top]+1;
		st[++top]=i;
	}
	st[top=0]=0;
	for (int i=1;i<=n;i++)
	{
		while (top&&a[st[top]]<=a[i]) top--;
		l2[i]=st[top]+1;
		st[++top]=i;
	}
	st[top=0]=n+1;
	for (int i=n;i>=1;i--)
	{
		while (top&&a[st[top]]>a[i]) top--;
		r1[i]=st[top]-1;
		st[++top]=i;
	}
	st[top=0]=n+1;
	for (int i=n;i>=1;i--)
	{
		while (top&&a[st[top]]<a[i]) top--;
		r2[i]=st[top]-1;
		st[++top]=i;
	}
	vector<node>c[105];
	for (int i=1;i<=n;i++)
	{
		int pop=__builtin_popcountll(a[i]);
		c[pop].push_back((node){l1[i],i,r1[i],1});
		c[pop].push_back((node){i+1,i,r1[i],-1});
		c[pop].push_back((node){l2[i],i,r2[i],1});
		c[pop].push_back((node){i+1,i,r2[i],-1});
	}
	t.build(1,1,n);
	for (int k=0;k<64;k++)
	{
		if (c[k].empty()) continue;
		sort(c[k].begin(),c[k].end());
		for (int i=1,j=0;i<=n+1;i++)
		{
			while (j<(int)c[k].size()&&c[k][j].x==i)
			t.add(1,1,n,c[k][j].l,c[k][j].r,c[k][j].v),j++;
			ans+=t.t[1][2];
		}
	}
	print(ans);
}

signed main(signed Hello,char *CodeForces[])
{
	(void)Hello,(void)CodeForces;
	int T=1;
//	int T=read();
	while (T--) GreenDay();
	
	return 0;
}