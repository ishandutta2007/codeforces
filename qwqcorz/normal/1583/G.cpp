#include<bits/stdc++.h>
using namespace std;
const int N=4e5+5;
const int p=1e9+7;

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
struct bit
{
	int n,t[N];
	void clear(){memset(t,0,sizeof(t));}
	void add(int x,int y){x++;for (;x<=n;x+=x&-x) t[x]=(t[x]+y)%p;}
	int query(int x){x++;int ret=0;for (;x;x&=x-1) ret=(ret+t[x])%p;return ret;}
}t;
struct node
{
	int l,r,is;
}a[N];
int f[N],g[N],F[N];

signed main()
{
	int n=read();
	for (int i=1;i<=n;i++) a[i].l=read(),a[i].r=read();
	int m=read();
	for (int i=1;i<=m;i++) a[read()].is=1;
	a[++n]=(node){0,n*2+1,0};
	sort(a+1,a+1+n,[&](node a,node b){return a.l>b.l;});
	t.n=n*2+1;
	for (int i=1;i<=n;i++)
	{
		g[i]=(t.query(a[i].r)+1)%p;
		t.add(a[i].r,g[i]);
	}
	t.clear();
	set<int>s;
	for (int i=1;i<=n;i++)
	{
		int zyk=0;
		auto tmp=s.lower_bound(a[i].r);
		if (tmp!=s.begin()) zyk=*prev(tmp),f[i]=F[zyk];
		f[i]=(f[i]+t.query(zyk-1)+1)%p;
		F[a[i].r]=f[i];
		t.add(a[i].r,g[i]);
		if (a[i].is) s.insert(a[i].r);
	}
	print(f[n]-1);
	
	return 0;
}