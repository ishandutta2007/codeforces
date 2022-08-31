#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
struct qt
{
	int val,id;
	qt(int val=0,int id=0):val(val),id(id){}
	bool operator<(const qt q) const
	{
		return val>q.val;
	}
};
int n,a[1000005],p[1000005],g[1000005],prime[1000005],pt,pn=1e6,mn[1000005],mx[1000005];
int c[1000005],nans[1000005];
char s[1000005];
vector<int> val[1000005];
priority_queue<qt> pq; 
void modify(int x,int v,int i)
{
	val[x][c[x]]=i;
	c[x]-=v;
	nans[x]=val[x][c[x]-1];
//	printf("modify:x=%d,v=%d,i=%d,nans=%d\n",x,v,i,nans[x]);
	pq.push(qt(nans[x],x));
}
int getans()
{
	while(!pq.empty()&&nans[pq.top().id]!=pq.top().val) pq.pop();
	return pq.top().val;
}
int main()
{
	p[1]=1;
	for(int i=2;i<=pn;i++)
	{
		if(!p[i]) prime[++pt]=i,g[i]=i;
		for(int j=1;j<=pt&&i*prime[j]<=pn;j++)
		{
			p[i*prime[j]]=1;
			g[i*prime[j]]=prime[j];
			if(i%prime[j]==0) break;
		}
	}
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	scanf("%s",s+1);
//	printf("---\n");
	for(int i=n;i>0;i--)
	{
		int u=a[i];
		while(u!=1)
		{
			int v=g[u];
			if(s[i]=='*') c[v]--;
			else c[v]++;
			mn[v]=min(mn[v],c[v]);
			mx[v]=max(mx[v],c[v]);
			u/=v;
		}
	}
//	printf("---\n");
	for(int i=1;i<=pn;i++)
		if(!p[i])
		{
			val[i].resize(mx[i]-mn[i]+3);
			for(int j=0;j<=mx[i]-mn[i]+2;j++)
				val[i][j]=n+1;
			c[i]=-mn[i]+1;
			nans[i]=n+1;
			pq.push(qt(nans[i],i));
		}
//	printf("---\n");
	ll ans=0;
	for(int i=n;i>0;i--)
	{
		int u=a[i];
		while(u!=1)
		{
			int v=g[u];
			if(s[i]=='*') modify(v,1,i);
			else modify(v,-1,i);
			u/=v;
		}
	//	printf("i=%d,getans=%d\n",i,getans());
		ans+=getans()-i;
	}
	printf("%lld\n",ans);
	return 0;
}