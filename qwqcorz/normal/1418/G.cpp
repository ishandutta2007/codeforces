#include<bits/stdc++.h>
#define ll long long
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
	struct node
	{
		int mn,tot,tag;
		friend node operator +(const node &a,const node &b)
		{
			int mn=min(a.mn,b.mn);
			int tot=(a.mn==mn?a.tot:0)+(b.mn==mn?b.tot:0);
			return (node){mn,tot,0};
		}
		void update(int x)
		{
			mn+=x;
			tag+=x;
		}
	}t[N*4];
	void push_down(int w)
	{
		if (!t[w].tag) return;
		t[ls].update(t[w].tag);
		t[rs].update(t[w].tag);
		t[w].tag=0;
	}
	void add(int w,int l,int r,int ql,int qr,int x)
	{
		if (qr<l||r<ql) return;
		if (ql<=l&&r<=qr) return t[w].update(x);
		push_down(w);
		add(ls,l,mid,ql,qr,x);
		add(rs,mid+1,r,ql,qr,x);
		t[w]=t[ls]+t[rs];
	}
	void build(int w,int l,int r)
	{
		if (l==r) return void(t[w]=(node){0,1,0});
		build(ls,l,mid);
		build(rs,mid+1,r);
		t[w]=t[ls]+t[rs];
	}
	#undef mid
	#undef rs
	#undef ls
}t;
int a[N],tot[N],now=0;
vector<int>p[N];
ll ans=0;

signed main(signed bangumi,char *ss1672[])
{
	(void)bangumi,(void)ss1672;
	int n=read();
	t.build(1,1,n);
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) p[i].push_back(0);
	for (int i=1;i<=n;i++)
	{
		int now=++tot[a[i]];
		t.add(1,1,n,p[a[i]].back()+1,i,1);
		p[a[i]].push_back(i);
		if (now>=3) t.add(1,1,n,p[a[i]][now-3]+1,p[a[i]][now-2],-1);
		if (now>=4) t.add(1,1,n,p[a[i]][now-4]+1,p[a[i]][now-3],1);
		if (t.t[1].mn==0) ans+=t.t[1].tot-(n-i);
	}
	print(ans);
	
	return 0;
}