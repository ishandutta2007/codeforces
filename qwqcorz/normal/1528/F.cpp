#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=(1<<18)+5;
const int p=998244353;

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
int s[N];
int power(int a,int b)
{
	int ret=1;
	for (;b;a=1LL*a*a%p,b/=2) if (b&1) ret=1LL*ret*a%p;
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
int F[N],G[N],lim=1,l=0,rev[N];
void NTT(int *a,int type)
{
	for (int i=0;i<lim;i++) if (i<rev[i]) swap(a[i],a[rev[i]]);
	for (int mid=1;mid<lim;mid*=2)
	{
		int Wn=power(type>0?3:power(3,p-2),(p-1)/mid/2);
		for (int len=mid*2,k=0;k<lim;k+=len)
		for (int i=k,w=1;i<k+mid;w=w*Wn%p,i++)
		{
			int x=a[i],y=w*a[i+mid]%p;
			a[i]=(x+y)%p;
			a[i+mid]=(x-y+p)%p;
		}
	}
	if (type<0)
	for (int i=0,invn=power(lim,p-2);i<lim;i++) a[i]=a[i]*invn%p;
}
void strling(int n)
{
	for (int i=0;i<=n;i++) F[i]=((i&1)?p-1:1)*inv[i]%p;
	for (int i=0;i<=n;i++) G[i]=power(i,n)*inv[i]%p;
	n++;
	while (lim<=n*2) lim*=2,l++;
	for (int i=0;i<lim;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(l-1));
	NTT(F,1);
	NTT(G,1);
	for (int i=0;i<lim;i++) F[i]=F[i]*G[i]%p;
	NTT(F,-1);
	for (int i=0;i<n;i++) s[i]=F[i];
}

signed main()
{
	int n=read(),k=read(),ans=0;
	ysgs(k);
	strling(k);
	for (int i=1,C=1;i<=min(n,k);i++)
	{
		C=C*(n-i+1)%p*power(i,p-2)%p;
		ans=(ans+C*s[i]%p*fact[i]%p*power(n+1,n-i)%p)%p;
	}
	print(ans);
	
	return 0;
}