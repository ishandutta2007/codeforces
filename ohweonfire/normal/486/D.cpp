#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn=4005;
const int mod=1000000007;
int next[maxn],head[maxn],to[maxn],a[maxn],cnt,n,m,x,y,d;
bool use[maxn];
inline void addedge(int x,int y)
{
	cnt++;
	next[cnt]=head[x];
	head[x]=cnt;
	to[cnt]=y;
}
LL dfs(int x,int root)
{
	use[x]=true;
	if(a[x]>a[root]+d||a[x]<a[root])
		return 0;
	if(a[x]==a[root]&&x<root)
		return 0;
	LL prod=1;
	for(int i=head[x];i;i=next[i])
		if(!use[to[i]])
			prod=prod*(dfs(to[i],root)+1)%mod;
	return prod;
}
int main()
{
	scanf("%d%d",&d,&n);
	LL ans=0;
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		addedge(x,y);
		addedge(y,x);
	}
	for(int i=1;i<=n;i++)
	{
		memset(use,0,sizeof(use));
		ans+=dfs(i,i);
		ans%=mod;
	}
	printf("%I64d\n",ans);
	return 0;
}