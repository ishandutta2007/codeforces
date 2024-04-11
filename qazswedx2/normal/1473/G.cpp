#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
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
int lim,len,rev[100005];
void getlim(int dep)
{
	lim=1,len=0;
	while(lim<=dep) lim<<=1,len++;
	for(int i=1;i<lim;i++)	
		rev[i]=(rev[i>>1]>>1)|((i&1)<<(len-1));
}
void ntt(int *a,int fl)
{
	for(int i=0;i<lim;i++)
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
int n,a[100005],b[100005],f[1005][5005],ft[1005],fr[1000005],infr[1000005],pn=1e6;
int tmp[100005],tmp2[100005];
inline int C(int x,int y)
{
	if(x<y||x<0||y<0) return 0;
	return 1ll*fr[x]*infr[y]%mod*infr[x-y]%mod;
}
int main()
{
	fr[0]=infr[0]=1;
	for(int i=1;i<=pn;i++)
		fr[i]=1ll*fr[i-1]*i%mod;
	infr[pn]=fpow(fr[pn],mod-2);
	for(int i=pn-1;i;i--)
		infr[i]=1ll*infr[i+1]*(i+1)%mod;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i],&b[i]);
	f[0][0]=1;
	ft[0]=1;
	for(int i=1;i<=n;i++)
	{
		ft[i]=ft[i-1]+a[i]-b[i];
		//for(int j=0;j<ft[i-1];j++)
		//	for(int k=0;k<ft[i];k++)
		//		f[i][k]=addmod(f[i][k]+1ll*f[i-1][j]*C(a[i]+b[i],b[i]+k-j)%mod);
		getlim(2*(ft[i-1]+ft[i]));
		for(int j=0;j<lim;j++)
			tmp[j]=tmp2[j]=0;
		for(int j=ft[i-1];j<2*ft[i-1];j++)
			tmp[j]=f[i-1][j-ft[i-1]];
		for(int j=0;j<ft[i-1]+ft[i];j++)
			tmp2[j]=C(a[i]+b[i],b[i]+j-ft[i-1]);
		ntt(tmp,1);
		ntt(tmp2,1);
		for(int j=0;j<lim;j++)
			tmp[j]=1ll*tmp2[j]*tmp[j]%mod;
		ntt(tmp,-1);
		for(int j=0;j<ft[i];j++)
			f[i][j]=tmp[j+2*ft[i-1]];
	}
	int ans=0;
	for(int i=0;i<ft[n];i++)
		ans=addmod(ans+f[n][i]);
	printf("%d\n",ans);
	return 0;
}