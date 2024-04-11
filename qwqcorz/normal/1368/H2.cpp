#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

char l[N],r[N],u[N],d[N];
int n,m,Q;
struct matrix
{
	int a[2][2];
	matrix(){memset(a,0x3f,sizeof(a));}
	friend matrix operator *(matrix a,matrix b)
	{
		matrix ret;
		for (int i=0;i<=1;i++)
		for (int k=0;k<=1;k++)
		for (int j=0;j<=1;j++)
		ret.a[i][j]=min(ret.a[i][j],a.a[i][k]+b.a[k][j]);
		return ret;
	}
};
struct segment_tree
{
	#define ls (w*2)
	#define rs (w*2+1)
	#define mid ((l+r)/2)
	struct node
	{
		matrix a[2][2];
		int sum[2][2],tag[2];
		node(){tag[0]=tag[1]=0;}
		node(bool A,bool B,int n)
		{
			for (int i=0;i<=1;i++)
			for (int j=0;j<=1;j++)
			{
				a[i][j].a[0][0]=(!A^i)+(!B^j);
				a[i][j].a[0][1]=(A^i)+(B^j)+n;
				a[i][j].a[1][0]=(!A^i)+(!B^j)+n;
				a[i][j].a[1][1]=(A^i)+(B^j);
			}
			memset(sum,0,sizeof(sum));
			memset(tag,0,sizeof(tag));
			sum[0][A]=1;
			sum[1][B]=1;
		}
		void flip(int x)
		{
			tag[x]^=1;
			swap(sum[x][0],sum[x][1]);
			for (int i=0;i<=1;i++)
			if (x==0) swap(a[0][i],a[1][i]);
				 else swap(a[i][0],a[i][1]);
		}
		friend node operator +(node a,node b)
		{
			node ret;
			for (int i=0;i<=1;i++)
			for (int j=0;j<=1;j++)
			{
				ret.a[i][j]=a.a[i][j]*b.a[i][j];
				ret.sum[i][j]=a.sum[i][j]+b.sum[i][j];
			}
			return ret;
		}
	}t[N*4];
	void push_down(int w)
	{
		for (int i=0;i<=1;i++)
		if (t[w].tag[i])
		{
			t[ls].flip(i);
			t[rs].flip(i);
			t[w].tag[i]=0;
		}
	}
	void flip(int w,int l,int r,int ql,int qr,int x)
	{
		if (ql<=l&&r<=qr) return t[w].flip(x);
		push_down(w);
		if (ql<=mid) flip(ls,l,mid,ql,qr,x);
		if (qr>mid) flip(rs,mid+1,r,ql,qr,x);
		t[w]=t[ls]+t[rs];
	}
	void build(int w,int l,int r,char *A,char *B,int n)
	{
		if (l==r) return t[w]=node(A[l]=='B',B[l]=='B',n),void();
		build(ls,l,mid,A,B,n);
		build(rs,mid+1,r,A,B,n);
		t[w]=t[ls]+t[rs];
	}
	#undef mid
	#undef rs
	#undef ls
}t1,t2;
int ask()
{
	int A[2],B[2],ret=1e9+7;
	A[0]=t1.t[1].sum[0][0];
	A[1]=t1.t[1].sum[0][1];
	B[0]=t1.t[1].sum[1][0];
	B[1]=t1.t[1].sum[1][1];
	for (int i=0;i<=1;i++)
	for (int j=0;j<=1;j++)
	ret=min(ret,A[i]+B[j]+t2.t[1].a[0][0].a[i][j]);
	A[0]=t2.t[1].sum[0][0];
	A[1]=t2.t[1].sum[0][1];
	B[0]=t2.t[1].sum[1][0];
	B[1]=t2.t[1].sum[1][1];
	for (int i=0;i<=1;i++)
	for (int j=0;j<=1;j++)
	ret=min(ret,A[i]+B[j]+t1.t[1].a[0][0].a[i][j]);
	return ret;
}

signed main()
{
	n=read(),m=read(),Q=read();
	scanf("%s%s%s%s",l+1,r+1,u+1,d+1);
	t1.build(1,1,m,u,d,n);
	t2.build(1,1,n,l,r,m);
	print(ask());
	while (Q--)
	{
		char c;
		cin>>c;
		int L=read(),R=read();
		if (c=='U') t1.flip(1,1,m,L,R,0);
		if (c=='D') t1.flip(1,1,m,L,R,1);
		if (c=='L') t2.flip(1,1,n,L,R,0);
		if (c=='R') t2.flip(1,1,n,L,R,1);
		print(ask());
	}
	
	return 0;
}