#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int mod=1e9+7;
inline int addmod(int x)
{
	return x>=mod?x-mod:x;
}
inline int submod(int x)
{
	return x<0?x+mod:x;
}
int T,n,a[1000005],b[1000005],bt,sum[1000005],f[1000005],g[1000005],c[1000005];
vector<int> val[1000005];
inline int lowbit(int x)
{
	return x&-x;
}
void modify(int x,int v)
{
	for(int i=x;i<=bt;i+=lowbit(i))
		sum[i]=addmod(sum[i]+v);
}
void modify2(int x)
{
	for(int i=x;i<=bt;i+=lowbit(i))
		sum[i]=0;
}
int query(int x)
{
	int ans=0;
	for(int i=x;i;i-=lowbit(i))
		ans=addmod(ans+sum[i]);
	return ans;
}
void solve(vector<int> v,int fl)
{
	int sz=v.size();
	for(int i=sz-1;i>=0;i--)
	{
		int u=v[i];
		if(fl==1&&i!=sz-1) g[u]=submod(query(bt)-query(a[u]));
		else g[u]=addmod(1+submod(query(bt)-query(a[u])));
		modify(a[u],g[u]);
	}
	for(int i=sz-1;i>=0;i--)
	{
		int u=v[i];
		modify2(a[u]);
	}
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		bt=0;
		for(int i=0;i<=n+2;i++)
			c[i]=0;
		for(int i=0;i<=n+1;i++)
			val[i].clear();
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			b[++bt]=a[i];
		}
		sort(b+1,b+bt+1);
		bt=unique(b+1,b+bt+1)-b-1;
		for(int i=1;i<=n;i++)
			a[i]=lower_bound(b+1,b+bt+1,a[i])-b;
		for(int i=1;i<=n;i++)
		{
			f[i]=addmod(1+query(a[i]-1));
			modify(a[i],f[i]);
		}
		for(int i=1;i<=n;i++)
			modify2(a[i]);
		vector<int> nw;
		for(int i=1;i<=n;i++)
			nw.push_back(i);
		solve(nw,0);
		int ans=0;
		for(int i=1;i<=n;i++)
		{
		//	printf("i=%d,f=%d,g=%d\n",i,f[i],g[i]);
			ans=(ans+1ll*f[i]*g[i])%mod;
		}
	//	printf("ans=%d\n",ans);
		for(int i=1;i<=n;i++)
			c[a[i]]=i;
		for(int i=bt-1;i>0;i--)
			c[i]=max(c[i],c[i+1]);
		c[bt+1]=0;
		for(int i=1;i<=n;i++)
		{
			int q=c[a[i]+1];
			val[max(q,i)].push_back(i);
		}
		for(int i=1;i<=n;i++)
			if(val[i].size())
			{
				solve(val[i],1);
				int sz=val[i].size();
				for(int j=0;j<sz;j++)
				{
					int u=val[i][j]; 
		//			printf("i=%d,sz=%d,u=%d,f=%d,g=%d\n",i,sz,u,f[u],g[u]);
					ans=submod(ans-1ll*f[u]*g[u]%mod);
				}
			}
		printf("%d\n",ans);
	}
	return 0;
}