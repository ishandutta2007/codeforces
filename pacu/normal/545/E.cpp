#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define INF 10000000000000000LL

int out[600000];
int w[600000];
vector<int> ans;

vector<vector<int> > edges;
long long dist[300000];
int epre[300000];
long long xtot;

struct cmp
{
	bool operator()(int a,int b)
	{
		if(dist[a]==dist[b])
			return a<b;
		return dist[a]<dist[b];
	}
};

set<int,cmp> S;
int N;

void dijkstra(int source)
{
	for(int i=0;i<N;i++)
	{
		dist[i] = INF;
		epre[i] = -1;
	}
	dist[source] = 0;
	for(int i=0;i<N;i++)
		S.insert(i);
	int cur,e;
	while(S.size() > 0)
	{
		cur = *S.begin();
		S.erase(cur);
		for(int j=0;j<edges[cur].size();j++)
		{
			e = edges[cur][j];
			if((dist[out[e]] > (dist[cur]+w[e]))||((dist[out[e]] == (dist[cur]+w[e]))&&(w[e]<w[epre[out[e]]])))
			{
				S.erase(out[e]);
				dist[out[e]] = dist[cur]+w[e];
				epre[out[e]] = e;
				S.insert(out[e]);
			}
		}
	}
	for(int i=0;i<N;i++)
		if(epre[i] != -1)
		{
			ans.push_back(epre[i]);
			xtot += w[epre[i]];
		}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int M;
	cin >> N >> M;
	for(int i=0;i<N;i++)
	{
		edges.push_back(vector<int>());
	}
	int a,b,c;
	for(int i=0;i<M;i++)
	{
		cin >> a >> b >> c;
		a--,b--;
		edges[a].push_back(2*i);
		edges[b].push_back(2*i+1);
		out[2*i] = b;
		out[2*i+1] = a;
		w[2*i] = w[2*i+1] = c;
	}
	int start;
	cin >> start;
	start--;
	dijkstra(start);
	cout << xtot << "\n";
	for(int i=0;i<ans.size();i++)
		cout << (ans[i]/2)+1 << " ";
	cout << "\n";
}