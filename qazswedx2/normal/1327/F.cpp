#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef pair<int,int> pii;
const int mod=998244353;
int n,m,k,b[500005][3],f[500005],c[500005],pre[500005],tpre[500005];
vector<pii> a[500005];
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
int main()
{
	scanf("%d%d%d",&n,&k,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&b[i][0],&b[i][1],&b[i][2]);
		a[b[i][1]].push_back(make_pair(b[i][0],b[i][2]));
	}
	int tans=1;
	for(int i=0;i<k;i++)
	{
	//	printf("i=%d\n",i);
		int las=-1;
		for(int j=0;j<=n;j++)
			c[j]=0;
		for(int j=1;j<=m;j++)
			if((b[j][2]&(1<<i)))
			{
				c[b[j][0]]++;
				c[b[j][1]+1]--;
			}
		for(int j=1;j<=n;j++)
			c[j]+=c[j-1];
		f[0]=pre[0]=tpre[0]=1;
		for(int j=1;j<=n;j++)
		{
			int sz=a[j].size(),nw=las;
			for(int l=0;l<sz;l++)
			{
				pii val=a[j][l];
				if((val.second&(1<<i))) continue;
				nw=max(nw,val.first-1);
			}
			if(c[j])
			{
				pre[j]=submod(pre[j-1]-(nw!=-1?tpre[nw]:0));
				pre[j]=addmod(pre[j]+(las!=-1?tpre[las]:0));
				las=nw;
				tpre[j]=tpre[j-1];
				f[j]=0;
			//	printf("j=%d,c=%d,pre=%d,f=%d\n",j,c[j],pre[j],f[j]);
				continue;
			}
			f[j]=pre[j-1];
			pre[j]=submod(pre[j-1]-(nw!=-1?tpre[nw]:0));
			pre[j]=addmod(pre[j]+(las!=-1?tpre[las]:0));
			pre[j]=addmod(pre[j]+f[j]);
			tpre[j]=addmod(tpre[j-1]+f[j]);
			//printf("j=%d,c=%d,pre=%d,f=%d,nw=%d,las=%d\n",j,c[j],pre[j],f[j],nw,las);
			las=nw;
		}
		tans=1ll*tans*pre[n]%mod;
	}
	printf("%d",tans);
	return 0;
}