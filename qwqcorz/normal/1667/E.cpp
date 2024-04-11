#include<bits/stdc++.h>
#define ll long long
#define poly vector<int>
using namespace std;
const int N=2e5+5;
const int p=998244353;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int power(int a,int b)
{
	int ret=1;
	for (;b;a=1LL*a*a%p,b/=2) if (b&1) ret=1LL*ret*a%p;
	return ret;
}
int fact[N],inv[N],f[N],g[N],tmp[N];
void ysgs(int n)
{
	for (int i=fact[0]=1;i<=n;i++) fact[i]=1LL*fact[i-1]*i%p;
	inv[n]=power(fact[n],p-2);
	for (int i=n;i>=1;i--) inv[i-1]=1LL*inv[i]*i%p;
}
int dpow(int n,int m)
{
	if (m==0) return 1;
	if (n<m) return 0;
	return 1LL*fact[n]*inv[n-m]%p;
}
poly rev;
int lim,l;
void NTT(vector<int>&a,int type)
{
	for (int i=0;i<lim;i++) if (i<rev[i]) swap(a[i],a[rev[i]]);
	for (int mid=1;mid<lim;mid*=2)
	{
		int Wn=power(type>0?3:power(3,p-2),(p-1)/mid/2);
		for (int len=mid*2,k=0;k<lim;k+=len)
		for (int i=k,w=1;i<k+mid;w=1LL*w*Wn%p,i++)
		{
			int x=a[i],y=1LL*w*a[i+mid]%p;
			a[i]=(x+y)%p;
			a[i+mid]=(x-y+p)%p;
		}
	}
	if (type<0)
	for (int i=0,invn=power(lim,p-2);i<lim;i++) a[i]=1LL*a[i]*invn%p;
}
poly operator *(poly a,poly b)
{
	lim=1,l=0;
	int n=a.size(),m=b.size();
	while (lim<=n+m) lim*=2,l++;
	rev.resize(lim);
	for (int i=0;i<lim;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(l-1));
	a.resize(lim),b.resize(lim);
	NTT(a,1),NTT(b,1);
	for (int i=0;i<lim;i++) a[i]=1LL*a[i]*b[i]%p;
	NTT(a,-1),a.resize(n+m-1);
	return a;
}

signed main()
{
	ysgs(2e5);
	int n=read(),m=(n+1)/2;
	poly A(n),B(n);
	for (int i=0;i<n;i++) A[i]=inv[i];
	for (int i=m-1;i<n-1;i++) B[i]=fact[n-i-2];
	poly C=A*B;
	for (int i=0;i<=n-2;i++) tmp[i]=1LL*fact[i]*inv[n-i-2]%p*C[i]%p;
	for (int i=1;i<=m;i++) f[i]=tmp[n-i];
	for (int i=n;i>=2;i--) g[i]=(g[i+1]+1LL*f[i]*fact[i-2])%p;
	for (int i=1;i<=m;i++) f[i]=(1LL*f[i]*fact[i-1]%p-g[i+1]+p)%p;
	f[1]=f[2];
	for (int i=1;i<=n;i++) print(f[i]," \n"[i==n]);
	
	return 0;
}