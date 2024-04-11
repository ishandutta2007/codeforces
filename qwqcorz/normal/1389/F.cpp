#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

struct segment_tree
{
	#define ls (w*2)
	#define rs (w*2+1)
	#define mid ((l+r)/2)
	int t[N*8],tag[N*8];
	void update(int w,int x){t[w]+=x,tag[w]+=x;}
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
		t[w]=max(t[ls],t[rs]);
	}
	#undef mid
	#undef rs
	#undef ls
}t1,t2;
int l[N],r[N],t[N],b[N*2],f[N*2],g[N*2];
vector<int>a[N*2][2];

signed main()
{
	int n=read(),cnt=0;
	for (int i=1;i<=n;i++) b[++cnt]=l[i]=read(),b[++cnt]=r[i]=read(),t[i]=read()-1;
	sort(b+1,b+1+cnt);
	cnt=unique(b+1,b+1+cnt)-b-1;
	for (int i=1;i<=n;i++)
	{
		l[i]=lower_bound(b+1,b+1+cnt,l[i])-b;
		r[i]=lower_bound(b+1,b+1+cnt,r[i])-b;
		a[r[i]][t[i]].push_back(l[i]);
	}
	for (int i=1;i<=cnt;i++)
	{
		for (int j:a[i][0]) t1.add(1,0,cnt,0,j-1,1);
		for (int j:a[i][1]) t2.add(1,0,cnt,0,j-1,1);
		f[i]=t1.t[1],g[i]=t2.t[1];
		t1.add(1,0,cnt,i,i,g[i]);
		t2.add(1,0,cnt,i,i,f[i]);
	}
	print(max(f[cnt],g[cnt]));
	
	return 0;
}