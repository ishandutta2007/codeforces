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
int w[2200005],len,lim,rev[1100005];
void getlim(int dep)
{
	lim=1,len=0;
	while(lim<=dep) lim<<=1,len++;
	for(int i=1;i<lim;i++)
	{
		rev[i]=(rev[i>>1]>>1)|((i&1)<<(len-1));
	}
}
ull tmp[1100005];
void ntt(int *a,int fl)
{
	for(int i=0;i<lim;i++)
		tmp[i]=a[rev[i]];
	for(int k=1;k<lim;k<<=1)
	{
		if(k==(1<<18))
		{
			for(int i=0;i<lim;i++)
				tmp[i]%=mod;
		}
		for(int i=0;i<lim;i+=(k<<1))
			for(int j=0;j<k;j++)
			{
				ull y=tmp[i+j+k]*w[j+k]%mod;
				tmp[i+j+k]=tmp[i+j]-y+mod;
				tmp[i+j]+=y;
			}
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
int n,m,fr[1000005],infr[1000005],inv[1000005],pw[1000005],pn=1e6;
char s[1000005];
int f[1000005],a[1000005],b[1000005],pre[1000005],suf[1000005];
int A[1100005],B[1100005]; 
void solve(int l,int r)
{
	if(l==r)
	{
		f[l]=addmod(f[l]+b[l]);
		return;
	}
	int mid=(l+r)/2;
	solve(l,mid);
	getlim(2*(r-l+1));
	for(int i=0;i<lim;i++)
		A[i]=B[i]=0;
	for(int i=0;i<=mid-l;i++)
		A[i]=f[i+l];
	for(int i=0;i<=r-l+1;i++)
		B[i]=a[i];
/*	printf("solve:l=%d,r=%d\n",l,r); 
	printf("f=");
	for(int i=1;i<=n;i++)
		printf("%d ",f[i]);
	printf("\n");
	for(int i=0;i<lim;i++)
		printf("%d ",A[i]);
	printf("\n");
	for(int i=0;i<lim;i++)
		printf("%d ",B[i]);
	printf("\n");*/
	ntt(A,1);
	ntt(B,1);
	for(int i=0;i<lim;i++)
		A[i]=1ll*A[i]*B[i]%mod;
	ntt(A,-1);
/*	for(int i=0;i<lim;i++)
		printf("%d ",A[i]);
	printf("\n");*/
	for(int i=mid+1;i<=r;i++)
		f[i]=addmod(f[i]+1ll*A[i-l]*inv[i-1]%mod);
	solve(mid+1,r);
}
inline int C(int x,int y)
{
	if(x<0||y<0||x<y) return 0;
	return 1ll*fr[x]*infr[y]%mod*infr[x-y]%mod;
}
int main()
{
	for(int k=1;k<(1<<19);k<<=1)
	{
		w[k]=1;
		int wn=fpow(3,(mod-1)/(k*2));
		for(int i=1;i<k;i++)
			w[i+k]=1ll*w[i+k-1]*wn%mod;
	}
	pw[0]=1;
	for(int i=1;i<=pn;i++)
		pw[i]=2ll*pw[i-1]%mod;
	fr[0]=infr[0]=1;
	for(int i=1;i<=pn;i++)
		fr[i]=1ll*fr[i-1]*i%mod;
	infr[pn]=fpow(fr[pn],mod-2);
	for(int i=pn-1;i>0;i--)
		infr[i]=1ll*infr[i+1]*(i+1)%mod;
	for(int i=1;i<=pn;i++)
		inv[i]=1ll*fr[i-1]*infr[i]%mod;
	scanf("%d%d%s",&n,&m,s+1);
	a[1]=1;
	int nw=1;
	for(int i=2;i<=n;i++)
	{
		a[i]=1ll*nw*infr[i-1]%mod;
		nw=2*nw%mod;
	}
	b[1]=1;
	solve(1,n);
/*	printf("f=");
	for(int i=1;i<=n;i++)
		printf("%d ",f[i]);
	printf("\n");*/
	for(int i=n;i>m;i--)
		suf[i]=f[n-i+1];
	for(int i=m;i>=1;i--)
	{
		int nw0=0,nw1=0;
		for(int j=i+1;j<=m+1;j++)
		{
			if(s[j-1]=='<')
			{
				if(nw1) break;
				nw0++; 
			}
			else
			{
				nw1++;
			}
			suf[i]=(suf[i]+1ll*suf[j]*C(nw0+nw1-2,nw0-1)%mod*infr[j-i-1])%mod;
		//	printf("i=%d,j=%d,suf=%lld\n",i,j,1ll*suf[i]*fr[n-i-1]);
			if(j==m+1)
			{
				int sum=(nw0+nw1-2>=0?pw[nw0+nw1-2]:0);
				for(int k=m+2;k<=n;k++)
				{
					int nw=nw0+(nw1+k-j)-2;
					if(nw1) suf[i]=(suf[i]+1ll*suf[k]*C(nw,nw0-1)%mod*infr[k-i-1])%mod;
					else
					{
						sum=submod(sum*2%mod-C(nw-1,nw0-2));
						suf[i]=(suf[i]+1ll*suf[k]*submod(pw[nw]-sum)%mod*infr[k-i-1])%mod;
					//	printf("i=%d,nw=%d,sum=%d,k=%d,%d,%d,suf=%lld\n",i,nw,sum,k,suf[k],submod(pw[nw]-sum),1ll*suf[i]*fr[n-i-1]);
					}
				}
			}
		}
		if(s[i]=='<') suf[i]=addmod(suf[i]+suf[i+1]);
		suf[i]=1ll*suf[i]*inv[n-i]%mod; 
	}
	pre[1]=1;
	for(int i=1;i<=m;i++)
	{
		if(i>1) pre[i]=1ll*pre[i]*inv[i-1]%mod;
		int nw0=0,nw1=0;
		for(int j=i+1;j<=m+1;j++)
		{
			if(s[j-1]=='<')
			{
				if(nw1) break;
				nw0++; 
			}
			else
			{
				nw1++;
			}
			pre[j]=(pre[j]+1ll*pre[i]*C(nw0+nw1-2,nw0-1)%mod*infr[j-i-1])%mod;
		//	printf("i=%d,j=%d,pre=%d\n",i,j,pre[j]);
			if(j==m+1)
			{
				int sum=(nw0+nw1-2>=0?pw[nw0+nw1-2]:0);
				for(int k=m+2;k<=n;k++)
				{
					int nw=nw0+(nw1+k-j)-2;
					if(nw1) pre[k]=(pre[k]+1ll*pre[i]*C(nw,nw0-1)%mod*infr[k-i-1])%mod;
					else
					{
						sum=submod(sum*2%mod-C(nw-1,nw0-2));
						pre[k]=(pre[k]+1ll*pre[i]*submod(pw[nw]-sum)%mod*infr[k-i-1])%mod;
					}
				}
			}
		}
		if(s[i]=='>') pre[i+1]=addmod(pre[i+1]+pre[i]);
	/*	printf("i=%d\n",i);
		for(int j=1;j<=n;j++)
			printf("%d ",pre[j]);
		printf("\n");*/
	}
	memset(b,0,sizeof(b));
	for(int i=m+1;i<=n;i++)
		b[i]=1ll*pre[i]*inv[i-1]%mod;
	memset(f,0,sizeof(f));
	solve(1,n);
	for(int i=m+1;i<=n;i++)
		pre[i]=f[i];
	//for(int i=1;i<=n;i++)
	//	printf("i=%d,pre=%lld,suf=%lld\n",i,1ll*pre[i]*fr[i-1]%mod,1ll*suf[i]*fr[n-i]%mod);
	int ans=0;
	for(int i=1;i<=n;i++)
		ans=(ans+1ll*pre[i]*suf[i])%mod;
	ans=1ll*ans*fr[n-1]%mod;
	printf("%d\n",ans); 
	return 0;
}