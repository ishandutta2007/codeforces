#include<bits/stdc++.h>
#define piir pair<double,int>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int N=2e5+5;
const double inf=1e18;

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
double delta(int p,int l,int y)
{
	if (y<0) return inf;
	if (y>=l) return 0;
	return p*1.0*l/(l+y)/(l+y+1);
}
double cost(int p,int l,int y)
{
	y=min(y,l);
	return p*1.0*y/(l+y);
}
double ans=0;
int p[N],l[N],y[N],n;
priority_queue<piir>q;
#define ls (w*2)
#define rs (w*2+1)
#define mid ((L+R)/2)
struct node
{
	piir mx,mn;
}t[N*4];
node operator +(const node &a,const node &b)
{
	return (node){max(a.mx,b.mx),min(a.mn,b.mn)};
}
void build(int w,int L,int R)
{
	if (L==R) return void(t[w]=(node){mk(delta(p[L],l[L],y[L]),L),mk(delta(p[L],l[L],y[L]-1),L)});
	build(ls,L,mid);
	build(rs,mid+1,R);
	t[w]=t[ls]+t[rs];
}
void update(int w,int L,int R,int x)
{
	if (L==R) return void(t[w]=(node){mk(delta(p[L],l[L],y[L]),L),mk(delta(p[L],l[L],y[L]-1),L)});
	if (x<=mid) update(ls,L,mid,x);
		   else update(rs,mid+1,R,x);
	t[w]=t[ls]+t[rs];
}
node query(int w,int L,int R,int ql,int qr)
{
	if (ql<=L&&R<=qr) return t[w];
	if (qr<=mid) return query(ls,L,mid,ql,qr);
	if (ql>mid) return query(rs,mid+1,R,ql,qr);
	return query(ls,L,mid,ql,qr)+query(rs,mid+1,R,ql,qr);
}
piir queryMax(int k)
{
	piir ret(-inf,0);
	if (k>1) ret=max(ret,query(1,1,n,1,k-1).mx);
	if (k<n) ret=max(ret,query(1,1,n,k+1,n).mx);
	return ret;
}
piir queryMin(int k)
{
	piir ret(inf,0);
	if (k>1) ret=min(ret,query(1,1,n,1,k-1).mn);
	if (k<n) ret=min(ret,query(1,1,n,k+1,n).mn);
	return ret;
}
#undef mid
#undef rs
#undef ls
void add(int k)
{
	ans-=cost(p[k],l[k],y[k]);
	ans+=cost(p[k],++l[k],y[k]);
	update(1,1,n,k);
}
void dec(int k)
{
	ans-=cost(p[k],l[k],y[k]);
	ans+=cost(p[k],--l[k],y[k]);
	update(1,1,n,k);
}

signed main()
{
	int t,Q;
	n=read(),t=read(),Q=read();
	for (int i=1;i<=n;i++) p[i]=read();
	for (int i=1;i<=n;i++) l[i]=read();
	for (int i=1;i<=n;i++) q.push(mk(delta(p[i],l[i],y[i]),i));
	while (t--)
	{
		piir now=q.top(); q.pop();
		int i=now.se; ans+=now.fi;
		q.push(mk(delta(p[i],l[i],++y[i]),i));
	}
	build(1,1,n);
	while (Q--)
	{
		int opt=read(),k=read();
		if (opt==1) add(k);
		if (opt==2) dec(k);
		piir tmp;
		if (delta(p[k],l[k],y[k]-1)<(tmp=queryMax(k)).fi)
		{
			ans-=delta(p[k],l[k],--y[k]),update(1,1,n,k);
			k=tmp.se;
			ans+=delta(p[k],l[k],y[k]++),update(1,1,n,k);
		}
		else if (delta(p[k],l[k],y[k])>(tmp=queryMin(k)).fi)
		{
			ans+=delta(p[k],l[k],y[k]++),update(1,1,n,k);
			k=tmp.se;
			ans-=delta(p[k],l[k],--y[k]),update(1,1,n,k);
		}
		printf("%.10lf\n",ans);
	}
	
	return 0;
}