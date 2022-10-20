#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3e5+5;
const int p=998244353;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int power(int a,int b)
{
	int ret=1;
	while (b)
	{
		if (b&1) ret=1LL*ret*a%p;
		a=1LL*a*a%p;
		b/=2;
	}
	return ret;
}
int fact[N],inv[N];
void ysgs(int n)
{
	for (int i=fact[0]=1;i<=n;i++) fact[i]=1LL*fact[i-1]*i%p;
	inv[n]=power(fact[n],p-2);
	for (int i=n;i>=1;i--) inv[i-1]=1LL*inv[i]*i%p;
}
int C(int n,int m)
{
	if (n<m||m<0) return 0;
	return 1LL*fact[n]*inv[m]%p*inv[n-m]%p;
}
int a[N],b[7],f[7][N];
int F[N*4],G[N*4],lim,l,rev[N*4];
void NTT(int *a,int type)
{
	for (int i=0;i<lim;i++) if (rev[i]<i) swap(a[i],a[rev[i]]);
	for (int mid=1;mid<lim;mid*=2)
	{
		int Wn=power(type>0?3:power(3,p-2),(p-1)/mid/2);
		for (int len=mid*2,k=0;k<lim;k+=len)
		for (int i=k,w=1;i<k+mid;i++,w=1LL*w*Wn%p)
		{
			int x=a[i],y=1LL*w*a[i+mid]%p;
			a[i]=(x+y)%p;
			a[i+mid]=(x-y+p)%p;
		}
	}
	if (type<0) for (int i=0,inv=power(lim,p-2);i<lim;i++) a[i]=1LL*a[i]*inv%p;
}
void get(int *a,int A,int B)
{
	lim=1,l=0;
	int n=2*A+B+1;
	while (lim<=n*2) lim*=2,l++;
	for (int i=0;i<lim;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(l-1));
	for (int i=0;i<lim;i++) F[i]=C(A*2,i);
	for (int i=0,pw=1;i<lim;i++,pw=pw*2%p) G[i]=1LL*C(B,i)*pw%p;
	NTT(F,1),NTT(G,1);
	for (int i=0;i<lim;i++) F[i]=1LL*F[i]*G[i]%p;
	NTT(F,-1);
	for (int i=1;i<=n;i++) a[i]=F[i-1];
}

signed main()
{
	ysgs(3e5);
	int n=read(),k=read();
	for (int i=1;i<=n;i++) a[read()]++;
	for (int i=1;i<=k;i++) b[i]=read();
	for (int i=1;i<=k;i++)
	{
		int A=0,B=0;
		for (int j=1;j<b[i];j++) A+=a[j]>=2,B+=a[j]==1;
		get(f[i],A,B);
	}
	int Q=read();
	while (Q--)
	{
		int x=read()/2,ans=0;
		for (int i=1;i<=k;i++) if (b[i]<=x&&x-b[i]<=n+1) ans=(ans+f[i][x-b[i]])%p;
		print(ans);
	}
	
	return 0;
}
/*
10 2
6410 4236 4091 8511 3563 7680 7072 1164 5139 8405
7995 9517
1
19056
*/