#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef unsigned long long ull;
const int mod=998244353;
inline int addmod(int x)
{
	return x>=mod?x-mod:x;
}
inline int submod(int x)
{
	return x<0?x+mod:x;
}
int fpow(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=1ll*ans*x%mod;
		x=1ll*x*x%mod;
		y/=2;
	}
	return ans;
}
int lim,len,rev[1000005],w[1000005];
int n,a[1000005],b[1000005],c[1000005],fa[1000005],fb[1000005],fc[1000005];
#define print(x) {printf(#x"=");for(int i=1;i<=n;i++) printf("%d ",x[i]);printf("\n");}
void getlim(int dep)
{
	lim=1,len=0;
	while(lim<=dep) lim<<=1,len++;
	for(int i=1;i<lim;i++)
		rev[i]=(rev[i>>1]>>1)|((i&1)<<(len-1)); 
}
ull tmp[1000005];
void ntt(int *a,int fl)
{
	for(int i=0;i<lim;i++)
		tmp[i]=a[rev[i]];
	for(int k=1;k<lim;k<<=1)
		for(int i=0;i<lim;i+=(k<<1))
			for(int j=0;j<k;j++)
			{
				int y=tmp[i+j+k]*w[j+k]%mod;
				tmp[i+j+k]=tmp[i+j]-y+mod;
				tmp[i+j]+=y;
			}
	for(int i=0;i<lim;i++)
		a[i]=tmp[i]%mod;
	if(fl==-1)
	{
		reverse(a+1,a+lim);
		int inv=fpow(lim,mod-2);
		for(int i=0;i<lim;i++)
			a[i]=1ll*a[i]*inv%mod;
	}
}
int A[1000005],B[1000005],C[1000005],FA[1000005],FB[1000005],FC[1000005];
int tmp1[1000005],tmp2[1000005],tmp3[1000005];
void solve(int l,int r)
{
	if(l==r)
	{
		a[l]=addmod(a[l]+fa[l]);
		b[l]=addmod(b[l]+fb[l]);
		c[l]=addmod(c[l]+fc[l]);
		return;
	}
	int mid=(l+r)/2;
	solve(l,mid);
	int len1=r-l+1,len2=mid-l+1;
	getlim(len1+len2);
	for(int i=0;i<lim;i++)
		A[i]=B[i]=C[i]=FA[i]=FB[i]=FC[i]=0;
	for(int i=0;i<len1;i++)
	{
		FA[i]=fa[i];
		FB[i]=fb[i];
		FC[i]=fc[i];
	}
	for(int i=0;i<len2;i++)
	{
		A[i]=a[i+l];
		B[i]=b[i+l];
		C[i]=c[i+l];
	}
	ntt(FA,1);
	ntt(FB,1);
	ntt(FC,1);
	ntt(A,1);
	ntt(B,1);
	ntt(C,1);
	for(int i=0;i<lim;i++)
	{
		tmp1[i]=(1ll*FA[i]*A[i]+1ll*FB[i]*B[i])%mod;
		tmp2[i]=(1ll*FB[i]*A[i]+1ll*FC[i]*B[i])%mod;
		tmp3[i]=(1ll*FC[i]*C[i]+1ll*FB[i]*B[i])%mod;
	}
	ntt(tmp1,-1);
	ntt(tmp2,-1);
	ntt(tmp3,-1);
	for(int i=mid+1,j=len2;i<=r;i++,j++)
	{
		a[i]=addmod(a[i]+tmp1[j]);
		b[i]=addmod(b[i]+tmp2[j]);
		c[i]=addmod(c[i]+tmp3[j]);
	}
	solve(mid+1,r);
}
int main()
{
	for(int k=1;k<(1<<18);k<<=1)
	{
		w[k]=1;
		int wn=fpow(3,(mod-1)/(k*2));
		for(int i=1;i<k;i++)
			w[i+k]=1ll*w[i+k-1]*wn%mod;
	}
	scanf("%d",&n);
	fa[1]=1;
	for(int i=2;i<=n;i++)
	{
		fa[i]=fa[i-2];
		if(i>=4) fa[i]=addmod(fa[i]+fa[i-4]);
	}
	for(int i=2;i<=n;i++)
	{
		fb[i]=fa[i-1];
		fc[i]=fa[i-2];
	}
	for(int i=1;i<=n;i++)
	{
		fa[i]=1ll*fa[i]*(i-1)%mod*(i-1)%mod;
		fb[i]=1ll*fb[i]*(i-1)%mod*(i-1)%mod;
		fc[i]=1ll*fc[i]*(i-1)%mod*(i-1)%mod;
	}
	solve(1,n);
/*	for(int i=1;i<=n;i++)
	{
		a[i]=fa[i];
		b[i]=fb[i];
		c[i]=fc[i];
		for(int j=0;j<i;j++)
		{
			a[i]=(a[i]+1ll*fa[i-j]*a[j]+1ll*fb[i-j]*b[j])%mod;
			b[i]=(b[i]+1ll*fb[i-j]*a[j]+1ll*fc[i-j]*b[j])%mod;
			c[i]=(c[i]+1ll*fc[i-j]*c[j]+1ll*fb[i-j]*b[j])%mod;
		}
	}*/
/*	print(fa);
	print(fb);
	print(fc);
	print(a);
	print(b);
	print(c);*/
	int ans=(1ll*fa[n]+fc[n])*n%mod;
	for(int i=1;i<=n;i++)
	{
		ans=(ans+(1ll*fa[i]*a[n-i]+2ll*fb[i]*b[n-i]+1ll*fc[i]*c[n-i])%mod*i)%mod;
	}
	printf("%d\n",ans);
	return 0;
}