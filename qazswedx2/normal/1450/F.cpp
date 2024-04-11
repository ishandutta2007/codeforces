#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
struct edge
{
	int v,vis,nxt;
}e[500005];
struct pt
{
	int val,id;
	pt(int val=0,int id=0):val(val),id(id){}
	bool operator<(const pt x) const
	{
		return val<x.val;
	}
};
priority_queue<pt> pq;
int n,h[100005],t,tt,f[100005],a[100005];
void add(int u,int v)
{
	e[++t].v=v;
	e[t].vis=0;
	e[t].nxt=h[u];
	h[u]=t;
}
int main()
{
	scanf("%d",&tt);
	while(tt--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			h[i]=f[i]=0;
		t=1;
		while(!pq.empty()) pq.pop();
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			f[a[i]]+=2;
		}
		for(int i=1;i<n;i++)
			if(a[i]!=a[i+1])
				add(a[i],a[i+1]),add(a[i+1],a[i]);
		int ct=2*n,cte=t/2,ans=0,fl=0;
		for(int i=1;i<=n;i++)
			pq.push(pt(f[i],i));
		while(!pq.empty())
		{
			while(!pq.empty()&&f[pq.top().id]!=pq.top().val) pq.pop();
			if(pq.empty()) break;
			int u=pq.top().id;
			pq.pop();
			int v=-1;
			for(int i=h[u];i;i=e[i].nxt)
			{
				h[u]=i;
				if(!e[i].vis)
				{
					v=e[i].v;
					e[i].vis=e[i^1].vis=1;
					break;
				}
			}
			if(v==-1)
			{
			//	printf("u=%d,cte=%d,ct=%d,f=%d\n",u,cte,ct,f[u]);
				ans=max(0,cte-(ct-(f[u]*2-2))/2);
				if(f[u]>ct/2+1) fl=1;
				break;
			}
		//	printf("u=%d,v=%d\n",u,v);
			f[u]--,f[v]--;
			pq.push(pt(f[u],u));
			pq.push(pt(f[v],v));
			ct-=2;
			cte--;
		}
		ans=t/2-ans;
		if(fl) printf("-1\n");
		else printf("%d\n",n-1-ans);
	}
	return 0;
}