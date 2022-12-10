#include<bits/stdc++.h>
using namespace std;
const int MAX=5e3+100;
int dis[MAX],n,m,q[MAX];
vector<int> g[MAX];
vector<pair<int,int> >  a[MAX];
priority_queue<pair<int,int> > s;
int main()
{
	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	memset(dis,-1,sizeof dis);
	cin>>n>>m;
	for (int i=0,v,u;i<m;i++) cin>>v>>u,v--,u--,g[v].push_back(u),g[u].push_back(v);
	int qq,w;
	cin>>w;
	for (int i=0,x,k,p;i<w;i++) cin>>x>>k>>p,x--,a[x].push_back({k,p});
	cin>>qq;
	while (qq--)
	{
		int v,need,mx,d=0,h=0,ss=0,t=0,flg=-1;
		long long sum=0,cnt=0;
		cin>>v>>need>>mx,v--;
		memset(dis,-1,sizeof dis);
		while (s.size()) s.pop();
		q[t++]=v,dis[v]=0;
		while (ss<t)
		{	
			int u=q[ss++];
			for(auto it:a[u])  
			{
				s.push({it.second,it.first}),cnt+=it.first,sum+=1LL*it.second*it.first;
				while (cnt>need)
				{
					auto it=s.top();
					s.pop();
					if (cnt-it.second>=need) cnt-=it.second,sum-=1LL*it.first*it.second;
					else it.second-=cnt-need,sum-=1LL*(cnt-need)*it.first,cnt=need,s.push(it);
				}
			}
			for (auto w:g[u]) if (dis[w]==-1) q[t++]=w,dis[w]=dis[u]+1;
			if (sum<=mx && cnt>=need) {cout<<dis[u]<<'\n',flg=0; break;}
		}
		if (flg==-1) cout<<-1<<'\n';
	}
	return 0;
}