# include <algorithm>
# include <utility>
# include <cstring>
# include <cassert>
# include <vector>
# include <cstdio>
# include <cmath>
# include <set>

using namespace std;

const int NMAX=1000;
const double INF=1000000000;

int cap[NMAX][NMAX],flow[NMAX][NMAX];
double cost[NMAX][NMAX];

char seen[NMAX];
int parent[NMAX];
double dist[NMAX];
bool cmp(const int& u,const int& v)
{
	return (dist[u]!=dist[v])?(dist[u]<dist[v]):u<v;
}

pair<int,double> mincostflow(int V,int s,int t)
{
	pair<int,double> ret(0,0);
	do
	{
		memset(seen,0,V);
		fill(dist,dist+V,INF);
		dist[s]=0;
		
		set<int,bool(*)(const int&,const int&)>djset(cmp);
		djset.insert(s);

		while(!djset.empty())
		{
			int u=*djset.begin();
			djset.erase(djset.begin());
			if(dist[u]>=INF/2)break;
			seen[u]=true;
			if(u==t)
			{
				ret.first++;
				for(int u=t;u!=s;u=parent[u])
				{
					flow[parent[u]][u]++;
					flow[u][parent[u]]--;
					ret.second+=cost[parent[u]][u];
				}
				break;
			}

			for(int v=0;v<V;v++)
			{
				if(seen[v])continue;
				if(cap[u][v]>flow[u][v]&&dist[u]+cost[u][v]<dist[v])
				{
					djset.erase(v);
					dist[v]=dist[u]+cost[u][v];
					djset.insert(v);
					parent[v]=u;
				}
			}
		}
	}while(seen[t]);
	return ret;
}

int main()
{
	int N;
	scanf("%d",&N);
	int x[N],y[N];
	for(int i=0;i<N;i++)
		scanf("%d%d",x+i,y+i);

	int V=2*N+2;
	for(int i=0;i<N;i++)
	{
		cap[0][i+1]=1;
		cap[i+N+1][2*N+1]=2;
		for(int j=0;j<N;j++)
		{
			if(y[i]<y[j])
			{
				cap[i+1][j+N+1]=1;
				cost[i+1][j+N+1]=sqrt((y[j]-y[i])*(y[j]-y[i])+(x[j]-x[i])*(x[j]-x[i]));
				cost[j+N+1][i+1]=-cost[i+1][j+N+1];
			}
		}
	}

	pair<int,double>ret=mincostflow(V,0,2*N+1);
	if(ret.first!=N-1)printf("-1\n");
	else printf("%.8lf\n",ret.second);

	return 0;
}