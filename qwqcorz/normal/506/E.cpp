#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=205;
const int M=305;
const int p=1e4+7;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int half(int x){return (x+1)/2;}
struct matrix
{
	int n,m,a[M][M];
	matrix(int _n=0,int _m=0)
	{
		n=_n,m=_m;
		for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) a[i][j]=0;
	}
	friend matrix operator *(matrix a,matrix b)
	{
		matrix ret(a.n,b.m);
		assert(a.m==b.n);
		for (int i=1;i<=a.n;i++)
		for (int k=1;k<=a.m;k++)
		for (int j=1;j<=b.m;j++)
		ret.a[i][j]=(ret.a[i][j]+a.a[i][k]*b.a[k][j])%p;
		return ret;
	}
	matrix power(matrix a,int b)
	{
		matrix ret=*this;
		while (b)
		{
			if (b&1) ret=ret*a;
			a=a*a;
			b/=2;
		}
		return ret;
	}
};
char a[N];
int dp[N][N][N];
int h(int l,int r,int k)
{
	if (k<0) return 0;
	int &now=dp[l][r][k];
	if (~now) return now;
	if (l>r) return now=k==0;
	if (a[l]==a[r]) now=h(l+1,r-1,k);
			   else now=(h(l+1,r,k-1)+h(l,r-1,k-1))%p;
	return now;
}
int DP[N][N][N];
int H(int l,int r,int k)
{
	if (k<0) return 0;
	int &now=DP[l][r][k];
	if (~now) return now;
	if (l>r) return now=k==0;
	now=0;
	if (a[l]==a[r]){if (l<r) now=H(l+1,r-1,k);}
			   else now=(H(l+1,r,k-1)+H(l,r-1,k-1))%p;
	return now;
}

signed main()
{
	memset(dp,-1,sizeof(dp));
	memset(DP,-1,sizeof(DP));
	scanf("%s",a+1);
	int n=strlen(a+1),len=n+read(),m=n-1+half(n)+1;
	matrix ans(1,m),e(m,m);
	ans.a[1][1]=1; 
	ans.a[1][n]=h(1,n,0);
	for (int i=1;i<n;i++)
	{
		e.a[i][i]=24;
		if (i+1<n) e.a[i][i+1]=1;
		e.a[i][m-half(n-i)]=h(1,n,i);
	}
	for (int i=n;i<m;i++)
	{
		e.a[i][i]=25;
		e.a[i][i+1]=1;
	}
	e.a[m][m]=26;
	int res=ans.power(e,half(len)).a[1][m];
	if (len%2==0) return print(res),0;
	ans.a[1][n]=H(1,n,0);
	for (int i=1;i<n;i++) e.a[i][m-half(n-i)]=H(1,n,i);
	e.a[m][m]=0;
	print(res=(res-ans.power(e,half(len)).a[1][m]+p)%p);
	
	return 0;
}