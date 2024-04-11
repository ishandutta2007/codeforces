#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
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
int lim,len,rev[1000005];
void getlim(int x)
{
	lim=1,len=0;
	while(lim<=x) lim<<=1,len++;
	for(int i=1;i<lim;i++)
		rev[i]=(rev[i>>1]>>1)|((i&1)<<(len-1));
}
void ntt(int *a,int fl)
{
	for(int i=1;i<lim;i++)
		if(i<rev[i])
			swap(a[i],a[rev[i]]);
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
int n,f[1000005],g[1000005],vis[3000005],b[200005],at;
vector<int> a[200005];
vector<int> getans(int l,int r)
{
	if(l==r) return a[l];
	int mid=(l+r)/2;
	vector<int> ls,rs,ans;
	ls=getans(l,mid);
	rs=getans(mid+1,r);
	int lsz=ls.size(),rsz=rs.size();
	getlim(lsz+rsz);
	for(int i=0;i<lim;i++)
		f[i]=g[i]=0;
	for(int i=0;i<lsz;i++)
		f[i]=ls[i];
	for(int i=0;i<rsz;i++)
		g[i]=rs[i];
	ntt(f,1);
	ntt(g,1);
	for(int i=0;i<lim;i++)
		f[i]=1ll*f[i]*g[i]%mod;
	ntt(f,-1);
	ans.resize(lsz+rsz-1);
	for(int i=0;i<lsz+rsz-1;i++)
		ans[i]=f[i];
	/*printf("l=%d,r=%d\n",l,r);
	for(int i=0;i<lsz+rsz-1;i++)
		printf("%d ",ans[i]);
	printf("\n");*/
	return ans;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		vis[b[i]]++;
	}
	for(int i=1;i<=n;i++)
		if(vis[b[i]])
		{
			at++;
			a[at].resize(vis[b[i]]+1);
			for(int j=0;j<vis[b[i]]+1;j++)
				a[at][j]=1;
			vis[b[i]]=0;
		}
/*	for(int i=1;i<=at;i++)
	{
		for(int j=0;j<(int)a[i].size();j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}*/
	vector<int> ans=getans(1,at);
	int sz=ans.size();
	printf("%d",ans[sz/2]);
	return 0;
}