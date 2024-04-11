#include<bits/stdc++.h>
#define int long long
#define ll long long
#define piir pair<int,int>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int N=5e4+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int k,n,p,a[N];
map<int,vector<piir>>mp;
struct matrix
{
	int a[2][2];
	friend matrix operator *(matrix a,matrix b)
	{
		matrix ret;
		memset(ret.a,0,sizeof(ret.a));
		for (int i=0;i<2;i++)
		for (int k=0;k<2;k++)
		for (int j=0;j<2;j++)
		ret.a[i][j]=(ret.a[i][j]+1LL*a.a[i][k]*b.a[k][j])%p;
		return ret;
	}
}ans=(matrix){{{0,1},{0,0}}},e;
matrix power(matrix a,int b)
{
	matrix ret=(matrix){{{1,0},{0,1}}};
	while (b)
	{
		if (b&1) ret=ret*a;
		a=a*a;
		b/=2;
	}
	return ret;
}
struct segment_tree
{
	#define ls (w*2)
	#define rs (w*2+1)
	#define mid ((l+r)/2)
	matrix t[N*4];
	void build(int w,int l,int r)
	{
		if (l==r) return t[w]=(matrix){{{0,a[l-1]},{1,a[l]}}},void();
		build(ls,l,mid);
		build(rs,mid+1,r);
		t[w]=t[ls]*t[rs];
	}
	void fix(int w,int l,int r,int x)
	{
		if (l==r) return t[w]=(matrix){{{0,a[l-1]},{1,a[l]}}},void();
		if (x<=mid) fix(ls,l,mid,x);
			   else fix(rs,mid+1,r,x);
		t[w]=t[ls]*t[rs];
	}
	matrix query(int w,int l,int r,int ql,int qr)
	{
		if (ql<=l&&r<=qr) return t[w];
		if (qr<=mid) return query(ls,l,mid,ql,qr);
		if (ql>mid) return query(rs,mid+1,r,ql,qr);
		return query(ls,l,mid,ql,qr)*query(rs,mid+1,r,ql,qr);
	}
	#undef mid
	#undef rs
	#undef ls
}t;
void zyk(vector<piir>&v)
{
	for (auto &i:v)
	{
		int x=i.fi;
		swap(a[x],i.se);
		if (x) t.fix(1,1,n,x);
		if (x<n) t.fix(1,1,n,x+1);
	}
}

signed main()
{
	k=read(),p=read(),n=read();
	if (k<2) return print(k%p),0;
	for (int i=0;i<n;i++) a[i]=read();
	a[n]=a[0],t.build(1,1,n),e=t.t[1];
	int m=read();
	for (int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		mp[x/n].push_back(mk(x%n,y));
		if (x%n==0) mp[x/n-1].push_back(mk(n,y));
	}
	mp[(--k-1)/n];
	int lst=-1;
	for (auto tmp:mp)
	{
		int now=tmp.fi; auto a=tmp.se;
		ans=ans*power(e,now-lst-1);
		zyk(a);
		if (now==(k-1)/n)
		{
			ans=ans*t.query(1,1,n,1,(k+n-1)%n+1);
			break;
		}
		else ans=ans*t.t[1];
		zyk(a);
		lst=now;
	}
	print(ans.a[0][1]);
	
	return 0;
}
/*
10 1000000000
3
1 2 1
2
7 3
5 4
*/