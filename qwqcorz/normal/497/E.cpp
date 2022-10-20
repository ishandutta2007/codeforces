#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int K=105;
const int R=65;
const int p=1e9+7;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

struct matrix
{
	int n,m;
	vector<vector<int>>a;
	matrix(int _n,int _m):n(_n),m(_m){a.resize(n);for (int i=0;i<n;i++) a[i].resize(m);};
	friend matrix operator *(matrix a,matrix b)
	{
		matrix ret(a.n,b.m);
		for (int i=0;i<a.n;i++)
		for (int k=0;k<a.m;k++)
		for (int j=0;j<b.m;j++)
		ret.a[i][j]=(ret.a[i][j]+1LL*a.a[i][k]*b.a[k][j])%p;
		return ret;
	}
	matrix power(int b)
	{
		assert(n==m);
		matrix ret(n,n),a=*this;
		for (int i=0;i<n;i++) ret.a[i][i]=1;
		while (b)
		{
			if (b&1) ret=ret*a;
			a=a*a;
			b/=2;
		}
		return ret;
	}
};
int b[R],m[R],len=0;

signed main()
{
	ll n=read();
	int k=read(),r=R;
	for (int i=0;i<r;i++) b[i]=1;
	for (ll tmp=n;tmp;tmp/=k) m[len++]=tmp%k;
	matrix first(1,k+1),tr(k+1,k+1),now(k+1,k+1),turn(k+1,k+1);
	first.a[0][k]=1;
	for (int i=0;i<=k;i++) tr.a[i][i]=1;
	now.a[0][k]=p-1,now.a[k][0]=1,now.a[k][k]=2;
	for (int i=1;i<k;i++) now.a[i][i]=1;
	turn.a[k][k]=1;
	for (int i=0;i<k;i++) turn.a[i][(i+1)%k]=1;
	for (int i=0;i<len;i++)
	{
		matrix g=turn.power(b[i]);
		tr=(now*g).power(m[i])*tr*g.power(k-m[i]);
		now=(now*g).power(k);
	}
	print((first*tr).a[0][k]);
	
	return 0;
}