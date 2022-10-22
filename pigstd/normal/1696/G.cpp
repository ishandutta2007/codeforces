#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
	char c=getchar();int x=0;bool f=0;
	for(;!isdigit(c);c=getchar())f^=!(c^45);
	for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
	if(f)x=-x;return x;
}
void ckmax(double &a,double b){a=(a>b?a:b);}

const double inf=1e18;
const int M=2e5+10;
int n,a[M],q,x,y;

struct matrix{double a[3][3];};

matrix init(int p)
{
	matrix c;
	c.a[0][1]=c.a[0][2]=c.a[1][2]=c.a[2][1]=c.a[2][0]=c.a[1][0]=-inf;
	c.a[0][0]=0,c.a[1][1]=p*1.0/(x+y),c.a[2][2]=p*1.0/y;
	return c;
}

matrix operator + (matrix a,matrix b)
{
	matrix c;
	for (int i=0;i<3;i++)for (int j=0;j<3;j++)
	{
		c.a[i][j]=-inf;
		for (int w1=0;w1<3;w1++)for (int w2=0;w2<3-w1;w2++)
			ckmax(c.a[i][j],a.a[i][w1]+b.a[w2][j]);
	}
	return c;
}

struct segment_tree
{
	struct tree
	{
		int tl,tr;
		matrix val;
	}t[M<<2];int ed[M];
	#define l(x) t[(x)].tl
	#define r(x) t[(x)].tr
	#define val(x) t[(x)].val
	#define lson k<<1
	#define rson k<<1|1
	void pushup(int k){val(k)=val(lson)+val(rson);}
	void build(int k,int l,int r)
	{
		l(k)=l,r(k)=r;
		if (l==r)return val(k)=init(a[l]),ed[l]=k,void();
		int Mid=(l+r)>>1;
		build(lson,l,Mid),build(rson,Mid+1,r);
		pushup(k); 
	}
	void upd(int k,int c)
	{
		a[k]=c;k=ed[k],val(k)=init(c);
		while(k!=1)k>>=1,pushup(k);
	}
	matrix query(int k,int l,int r)
	{
		if (l(k)>=l&&r(k)<=r)return val(k);
		if (r(lson)<l)return query(rson,l,r);
		else if (l(rson)>r)return query(lson,l,r);
		return query(lson,l,r)+query(rson,l,r);
	}
}T;

signed main()
{
	n=read(),q=read(),x=read(),y=read();
	if (x>y)swap(x,y);
	for (int i=1;i<=n;i++)a[i]=read();
	T.build(1,1,n);
	while(q--)
	{
		int opt=read();
		if (opt==1)
		{
			int x=read(),b=read();
			T.upd(x,b);
		}
		else
		{
			int l=read(),r=read();
			double ans=-inf;
			matrix c=T.query(1,l,r);
			for (int i=0;i<3;i++)for (int j=0;j<3;j++)ckmax(ans,c.a[i][j]);
			printf("%.12lf\n",ans); 
		}
	}
	return 0;
}