#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1e6+1e3+7;

int n;

ll ans,m,a[N],b[N],vis[N],id[N],pre[N];

struct node{
	ll a,b;
}v[N];

bool cmp(node a,node b)
{
	return a.b>b.b||(a.b==b.b&&a.a>b.a);
}

bool cmpa(int x,int y)
{
	return v[x].a>v[y].a;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans=0;
		for(int i=1;i<=n;i++)
			vis[i]=0;
		scanf("%lld%d",&m,&n);
		pre[0]=0;
		for(int i=1;i<=n;i++)
			scanf("%lld%lld",&v[i].a,&v[i].b),id[i]=i;
		sort(v+1,v+n+1,cmp);
		sort(id+1,id+n+1,cmpa);
		int now=0;
		ll va=0;
		for(int i=1;i<=n;i++)
		{
			while(v[id[now+1]].a>v[i].b&&now+1<=n&&m)
				m--,now++,va+=v[id[now]].a,vis[id[now]]=1;
			if(m)
			{
				if(vis[i])
					ans=max(ans,va+m*v[i].b);
				else
					ans=max(ans,va+v[i].a+(m-1)*v[i].b);
			}
			else
				ans=max(ans,va);
			if(!m)
				break;
		}	
		printf("%lld\n",ans);
	}
}