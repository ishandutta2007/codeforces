#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
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
void print(int x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
void add(int &x,int y){x+=y;if (x>=p) x-=p;}
struct Vector{int a[2];}V=(Vector){0,1};
struct Matrix{int a[2][2];}M=(Matrix){{{0,1},{1,1}}},unit=(Matrix){{{1,0},{0,1}}};
bool operator ==(const Matrix &a,const Matrix &b)
{
	for (int i=0;i<2;i++)
	for (int j=0;j<2;j++)
	if (a.a[i][j]!=b.a[i][j])
	return 0;
	return 1;
}
Vector operator +(const Vector &a,const Vector &b)
{
	Vector ret=(Vector){{0,0}};
	for (int i=0;i<2;i++) ret.a[i]=(a.a[i]+b.a[i])%p;
	return ret;
}
Matrix operator +(const Matrix &a,const Matrix &b)
{
	Matrix ret=(Matrix){{0,0}};
	for (int i=0;i<2;i++)
	for (int j=0;j<2;j++)
	ret.a[i][j]=(a.a[i][j]+b.a[i][j])%p;
	return ret;
}
Vector operator *(const Vector &a,const Matrix &b)
{
	Vector ret=(Vector){{0,0}};
	for (int i=0;i<2;i++)
	for (int j=0;j<2;j++)
	add(ret.a[j],1LL*a.a[i]*b.a[i][j]%p);
	return ret;
}
Matrix operator *(const Matrix &a,const Matrix &b)
{
	Matrix ret=(Matrix){{{0,0},{0,0}}};
	for (int i=0;i<2;i++)
	for (int k=0;k<2;k++)
	for (int j=0;j<2;j++)
	add(ret.a[i][j],1LL*a.a[i][k]*b.a[k][j]%p);
	return ret;
}
Matrix power(Matrix a,int b)
{
	Matrix ret=unit;
	while (b)
	{
		if (b&1) ret=ret*a;
		a=a*a;
		b/=2;
	}
	return ret;
}
#define ls (w*2)
#define rs (w*2+1)
#define mid ((l+r)/2)
struct node
{
	Vector val;
	Matrix tag;
	void mul(Matrix x)
	{
		val=val*x;
		tag=tag*x;
	}
}t[N*4];
Vector a[N];
node operator +(const node &a,const node &b)
{
	node ret;
	ret.val=a.val+b.val;
	ret.tag=unit;
	return ret;
}
void push_down(int w)
{
	if (t[w].tag==unit) return;
	t[ls].mul(t[w].tag);
	t[rs].mul(t[w].tag);
	t[w].tag=unit;
}
void build(int w,int l,int r)
{
	if (l==r)
	{
		t[w].val=a[l];
		t[w].tag=unit;
		return;
	}
	build(ls,l,mid);
	build(rs,mid+1,r);
	t[w]=t[ls]+t[rs];
}
void mul(int w,int l,int r,int ql,int qr,Matrix x)
{
	if (qr<l||r<ql) return;
	if (ql<=l&&r<=qr) return t[w].mul(x);
	push_down(w);
	mul(ls,l,mid,ql,qr,x);
	mul(rs,mid+1,r,ql,qr,x);
	t[w]=t[ls]+t[rs];
}
Vector query(int w,int l,int r,int ql,int qr)
{
	if (qr<l||r<ql) return (Vector){0,0};
	if (ql<=l&&r<=qr) return t[w].val;
	push_down(w);
	return query(ls,l,mid,ql,qr)+query(rs,mid+1,r,ql,qr);
}
#undef ls
#undef rs
#undef mid

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read(),m=read();
	for (int i=1;i<=n;i++)
	{
		int x=read()-1;
		a[i]=V*power(M,x);
	}
	build(1,1,n);
	for (int i=1;i<=m;i++)
	{
		int opt=read(),l=read(),r=read(),x=opt==1?read():0;
		if (opt==1) mul(1,1,n,l,r,power(M,x));
		if (opt==2) print(query(1,1,n,l,r).a[1]);
	}
	
	return 0;
}