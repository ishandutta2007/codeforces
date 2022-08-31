#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int lim,len,rev[1000005],mod=998244353;
void getlim(int x)
{
	lim=1,len=0;
	while(lim<=x) lim<<=1,len++;
	for(int i=1;i<lim;i++)
		rev[i]=((rev[i>>1]>>1)|((i&1)<<(len-1)));
	//for(int i=0;i<lim;i++)
	//	printf("%d ",rev[i]);
	//printf("\n");
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
inline int addmod(int x)
{
	return x>=mod?x-mod:x;
}
inline int submod(int x)
{
	return x<0?x+mod:x;
}
void ntt(int *a,int fl)
{
	for(int i=1;i<lim;i++)
		if(i<rev[i]) swap(a[i],a[rev[i]]);
	for(int k=1;k<lim;k<<=1)
	{
		int wn=fpow(3,(mod-1)/(k*2));
		for(int i=0,r=k*2;i<lim;i+=r)
		{
			int w=1;
			for(int j=0;j<k;j++,w=1ll*w*wn%mod)
			{
				int x=a[i+j],y=1ll*w*a[i+j+k]%mod;
				a[i+j]=addmod(x+y);
				a[i+j+k]=submod(x-y);
			}
		}
	}
	if(fl==-1)
	{
		reverse(a+1,a+lim);
		int inv=fpow(lim,mod-2);
		for(int i=0;i<lim;i++)
			a[i]=1ll*a[i]*inv%mod;
	}
}
int n,fr[100005],infr[100005]; 
int nans[30][1000005];
void getans(int dep,int l,int r)
{
	if(l==r)
	{
		nans[dep][0]=l-1;
		nans[dep][1]=1;
		getlim(2);
		return;
	}
	int mid=(l+r)/2;
	getans(dep+1,l,mid);
	for(int i=0;i<=mid-l+1;i++)
		nans[dep][i]=nans[dep+1][i];
	getans(dep+1,mid+1,r);
	getlim(r-l+1);
	for(int i=mid-l+2;i<lim;i++)
		nans[dep][i]=0;
	for(int i=r-mid+1;i<lim;i++)
		nans[dep+1][i]=0;
	ntt(nans[dep],1);
	ntt(nans[dep+1],1);
	for(int i=0;i<lim;i++)
		nans[dep][i]=1ll*nans[dep][i]*nans[dep+1][i]%mod;
	ntt(nans[dep],-1);
	for(int i=r-l+2;i<lim;i++)
		nans[dep][i]=0;
	/*printf("dep=%d,l=%d,r=%d,nans=",dep,l,r);
	for(int i=0;i<=r-l+1;i++)
		printf("%d ",nans[dep][i]);
	printf("\n");*/
}
int getansc(int x,int y)
{
	return 1ll*fr[x]*infr[y]%mod*infr[x-y]%mod;
}
int main()
{
	int a,b;
	scanf("%d%d%d",&n,&a,&b);
	fr[0]=infr[0]=1;
	for(int i=1;i<=n;i++)
		fr[i]=1ll*fr[i-1]*i%mod;
	infr[n]=fpow(fr[n],mod-2);
	for(int i=n-1;i>0;i--)
		infr[i]=1ll*infr[i+1]*(i+1)%mod;
	if(a+b-1>n||a==0||b==0)
	{
		printf("0");
		return 0;
	}
	if(n==1)
	{
		printf("1");
		return 0;
	}
	getans(0,1,n-1);
	//for(int i=0;i<=n;i++)
	//	printf("%d ",nans[0][i]);
	//printf("\n");
	printf("%lld",1ll*getansc(a+b-2,a-1)*nans[0][a+b-2]%mod);
	return 0;
}