#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=987564313;
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
int n,ff[55],vis[55],gt,g[55][55],d[55],f[10000005],lg[10000005];
int tmp[10000005];
int cnt[10000005];
char s[55][55];
int find(int x)
{
	if(ff[x]==x) return x;
	return ff[x]=find(ff[x]);
}
void link(int x,int y)
{
	x=find(x),y=find(y);
	if(x==y) return;
	ff[x]=y;
}
void fwt()
{
	for(int k=1;k<(1<<n);k<<=1)
		for(int i=0,r=k*2;i<(1<<n);i+=r)
			for(int j=0;j<k;j++)
				f[i+j+k]+=f[i+j];
}
bool check()
{
	int ans=0;
	for(int i=0;i<(1<<n);i++)
		if((n-cnt[i])%2==0) ans=addmod(ans+tmp[i]);
		else ans=submod(ans-tmp[i]);
	return ans;
}
int main()
{
	for(int i=0;i<=22;i++)
		lg[1<<i]=i;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		ff[i]=i;
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(s[i][j]=='A') link(i,j);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(s[i][j]!='A'&&find(i)==find(j))
			{
				printf("-1\n");
				return 0;
			}
//	printf("---");
	for(int i=1;i<=n;i++)
		if(find(i)!=i&&!vis[find(i)])
			vis[find(i)]=++gt;
	for(int i=0;i<=gt;i++)
		for(int j=0;j<=gt;j++)
			g[i][j]=1;
	for(int i=1;i<=n;i++)
		if(vis[find(i)])
			for(int j=1;j<=n;j++)
				if(vis[find(j)])
				{
					int u=vis[find(i)],v=vis[find(j)];
					if(u==v) continue;
					g[u][v]&=(s[i][j]=='O');
				}
	int ans=n+gt-1;
	if(!gt)
	{
		printf("%d\n",ans);
		return 0;
	}
//	printf("ans=%d\n",ans);
	n=gt;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			d[i]|=(g[i][j]<<(j-1));
//	for(int i=1;i<=n;i++)
//		printf("i=%d,d=%d\n",i,d[i]);
	f[0]=1;
	for(int i=1;i<(1<<n);i++)
	{
		cnt[i]=cnt[i/2]+i%2;
		int nw=lg[i&-i]+1;
		f[i]=f[i-(i&-i)]&&((d[nw]&i)==i);
	}
//	for(int i=0;i<(1<<n);i++)
//		printf("%d ",f[i]);
//	printf("\n");
	fwt();
//	for(int i=0;i<(1<<n);i++)
//		printf("%d ",f[i]);
//	printf("\n");
	memcpy(tmp,f,sizeof(tmp));
	for(int i=1;;i++)
	{
		if(check())
		{
			ans-=(n-i);
			break;
		}
		for(int j=0;j<(1<<n);j++)
			tmp[j]=1ll*tmp[j]*f[j]%mod;
	}
	printf("%d\n",ans);
	return 0;
}