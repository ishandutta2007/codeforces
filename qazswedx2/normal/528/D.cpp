#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int lim=1,len=0,rev[1000005],mod=998244353;
void getlim(int x)
{
	lim=1;len=0;
	while(lim<=x) lim<<=1,len++;
	for(int i=1;i<lim;i++)
		rev[i]=(rev[i>>1]>>1)|((i&1)<<(len-1));
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
int n,m,k,c[1000005][5],f[1000005],g[1000005],a[1000005],b[1000005],vis[100005],sumg[1000005],ans[1000005],tans;
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	getlim(2*n);
	vis['A']=1,vis['C']=2,vis['G']=3,vis['T']=4;
	for(int i=m-1;i<n;i++)
		ans[i]=1;
	for(int i=1;i<=n;i++)
	{
		char ch;
		scanf(" %c",&ch);
		b[i]=vis[ch];
		for(int j=1;j<=4;j++)
			c[i][j]=c[i-1][j]+(vis[ch]==j);
	}
	for(int i=1;i<=m;i++)
	{
		char ch;
		scanf(" %c",&ch);
		a[i]=vis[ch];
	}
	for(int i=1;i<=4;i++)
	{
		int sum=0;
		for(int j=0;j<lim;j++)
			g[j]=f[j]=sumg[j]=0;
		for(int j=1;j<=m;j++)
			if(a[j]==i)
				f[j-1]=1,sum++;
		for(int j=1;j<=n;j++)
		{
			int nw=c[j+k>n?n:j+k][i]-c[j-k-1<0?0:j-k-1][i];
			sumg[j]=sumg[j-1];
			if(!nw) continue;
			g[j-1]=1;
			sumg[j]++;
		}
		reverse(f,f+m);
		/*printf("i=%d\n",i);
		for(int j=0;j<m;j++)
			printf("%d ",f[j]);
		printf("\n");
		for(int j=0;j<n;j++)
			printf("%d ",g[j]);
		printf("\n");*/
		ntt(f,1);
		ntt(g,1);
		for(int j=0;j<lim;j++)
			f[j]=1ll*f[j]*g[j]%mod;
		ntt(f,-1);
		/*printf("newf=");
		for(int j=0;j<m;j++)
			printf("%d ",f[j]);
		printf("\n");*/
		for(int j=m-1;j<n;j++)
		{
			int nw=sum-f[j];
			if(nw) ans[j]=0;
		}
	}
	for(int i=m-1;i<n;i++)
		if(ans[i]) tans++;
	printf("%d",tans);
	return 0;
}