#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
struct pt
{
	int l,r,id;
	bool operator<(const pt x) const
	{
		return r<x.r;
	}
}p[500005];
int tt,n,a[500005],vis[500005];
priority_queue<pt> pq;
int main()
{
	scanf("%d",&tt);
	while(tt--)
	{
		while(!pq.empty()) pq.pop();
		int mid=0,ct=0,ctt=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
			if(a[i]==0) ct++;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0) ctt++;
			if(ctt>=ct/2)
			{
				mid=i;
				break;
			}
		}
		for(int i=1;i<=n;i++)
			p[i].l=0,p[i].r=n+1,p[i].id=i,vis[i]=0;
		for(int i=mid;i>=1;i--)
			if(a[i]&&!p[a[i]].l)
				p[a[i]].l=i;
			else if(a[i]) a[i]=-1;
		for(int i=mid+1;i<=n;i++)
			if(a[i]&&p[a[i]].r==n+1)
				p[a[i]].r=i;
			else if(a[i]) a[i]=-1;
		int ans=0;
		for(int i=mid;i>=1;i--)
		{
			if(a[i]>0)
			{
				pq.push(p[a[i]]);
				continue;
			}
			if(a[i]==-1) continue;
			if(pq.empty()) continue;
			int u=pq.top().id;
			pq.pop();
			//printf("i=%d,u=%d\n",i,u);
			ans++;
			vis[u]=1;
		}
		int nw=0;
		for(int i=n;i>mid;i--)
		{
			if(a[i]>0&&!vis[a[i]])
			{
				if(nw)
				{
					nw--,ans++;
				//	printf("i=%d,nw=%d\n",i,nw);
				}
				continue;
			}
			if(a[i]==0) 
				nw++;
			//printf("i=%d,a=%d\n",i,a[i]);
		}
		ans=min(ans,ct/2);
		printf("%d\n",ans);
	}
	return 0;
}