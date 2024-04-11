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
int lim,len,rev[1100005],w[2200005];
void getlim(int dep)
{
	lim=1,len=0;
	while(lim<=dep) lim<<=1,len++;
	for(int i=1;i<lim;i++)
		rev[i]=(rev[i>>1]>>1)|((i&1)<<(len-1));
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
		for(int i=0,r=k*2;i<lim;i+=r)
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
int n,m,a[1000005],vis[1000005],f[1000005],g[1000005],tans[1000005],pre[1000005],suf[1000005];
int pw[1000005],c[1000005],pn=1e6;
void solve(int l,int r)
{
	if(l==r)
	{
		tans[l]=addmod(tans[l]+pw[c[n]-vis[l]]);
		return;
	}
	int mid=(l+r)/2;
	getlim(r-l+2);
	for(int i=0;i<lim;i++)
		f[i]=g[i]=0;
	for(int i=l;i<=mid;i++)
		f[i-l]=pw[c[i-1]];
	for(int i=mid+1;i<=r;i++)
		g[i-mid-1]=pw[c[n]-c[i]];
/*	printf("solve:l=%d,r=%d\n",l,r);
	for(int i=0;i<lim;i++)
		printf("%d ",f[i]);
	printf("\n");
	for(int i=0;i<lim;i++)
		printf("%d ",g[i]);
	printf("\n");*/ 
	ntt(f,1);
	ntt(g,1);
	for(int i=0;i<lim;i++)
		f[i]=1ll*f[i]*g[i]%mod;
	ntt(f,-1);
	for(int i=0;i<lim;i++)
		if(f[i]&&(l+mid+1+i)%2==0)
		{
			tans[(l+mid+1+i)/2]=addmod(tans[(l+mid+1+i)/2]+f[i]);
		}
	solve(l,mid);
	solve(mid+1,r);
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
		pw[i]=pw[i-1]*2%mod;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
	{
		int x;
		scanf("%d",&x);
		vis[x]=1;
	}
	for(int i=1;i<=n;i++)
		c[i]=vis[i]+c[i-1];
	pre[0]=1;
	for(int i=1;i<=n;i++)
		pre[i]=addmod(pre[i-1]+pw[c[i]]);
	for(int i=1;i<=n;i++)
		if(2*i-n-2>=0)
			tans[i]=pre[2*i-n-2];
	suf[n+1]=1;
	for(int i=n;i>0;i--)
		suf[i]=addmod(suf[i+1]+pw[c[n]-c[i-1]]);
	for(int i=1;i<=n;i++)
		if(2*i+1<=n+1)
			tans[i]=suf[2*i+1];
	solve(1,n);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		tans[i]=submod(tans[i]-max(i,n-i+1));
	//	printf("i=%d,tans=%d\n",i,tans[i]);
		ans=addmod(ans+1ll*tans[i]*a[i]%mod);
	//	ans=submod(ans-1ll*max(i,n-i+1)*a[i]%mod);
	}
	ans=1ll*ans*fpow(pw[m]-1,mod-2)%mod;
	printf("%d\n",ans);
	return 0;
}