#include <iostream>
#include <vector>
using namespace std;
#define INF 1000000000

int nxt[11000], cap[11000], flow[11000];
vector<int> edges[1000];

vector<int> stak;
int vis[1000];
int nVert;

int source,dest;

bool findPath(int i,int dfsIndex)
{
	if(i == dest)
		return 1;
	vis[i] = dfsIndex;
	for(int j=0;j<edges[i].size();j++)
		if(vis[nxt[edges[i][j]]] != dfsIndex && cap[edges[i][j]] > 0)
		{
			stak.push_back(edges[i][j]);
			if(findPath(nxt[edges[i][j]],dfsIndex))
				return 1;
			stak.pop_back();
		}
	return 0;
}

int fflow()
{
	int lowCap;
	for(int i=0;i<nVert;i++)
		vis[i] = 0;
	int tot = 0;
	for(int dfsIndex = 1; findPath(source,dfsIndex); dfsIndex++)
	{
//		cout << "PATH 1\n";
		lowCap = INF;
		for(int j=0;j<stak.size();j++)
			lowCap = min(lowCap,cap[stak[j]]);
		tot += lowCap;
		for(int j=0;j<stak.size();j++)
		{
//			cout << '(' << stak[j] << ") " << nxt[stak[j]] << ' ';
			flow[stak[j]] += lowCap;
			cap[stak[j]] -= lowCap;
			flow[stak[j]^1] -= lowCap;
			cap[stak[j]^1] += lowCap;
		}
//		cout << '\n';
		stak.clear();
	}
//	cout << tot << '\n';
	return tot;
}

int travels[1000][1000];

int main()
{
	int N,M;
	int a,b;
	
	cin >> N >> M;
	
	nVert = 2*N + 2;
	source = 0;
	dest = 2*N+1;
	
	int soldiers = 0;
	int soldiers2 = 0;
	int E = 0;
	
	for(int i=0;i<N;i++)
	{
		edges[source].push_back(E);
		nxt[E] = i+1;
		cin >> cap[E];
		soldiers += cap[E];
		E++;
		
		edges[i+1].push_back(E);
		nxt[E] = source;
		cap[E] = 0;
		E++;
	}
	
	for(int i=0;i<N;i++)
	{
		edges[i+1+N].push_back(E);
		nxt[E] = dest;
		cin >> cap[E];
		soldiers2 += cap[E];
		E++;
		
		edges[dest].push_back(E);
		nxt[E] = i+1+N;
		cap[E] = 0;
		E++;
	}
	
	for(int j=0;j<M;j++)
	{
		cin >> a >> b;
		edges[a].push_back(E);
		nxt[E] = b+N, cap[E] = INF, flow[E] = 0;
		E++;
		edges[b+N].push_back(E);
		nxt[E] = a, cap[E] = 0, flow[E] = 0;
		E++;
		
		edges[b].push_back(E);
		nxt[E] = a+N, cap[E] = INF, flow[E] = 0;
		E++;
		edges[a+N].push_back(E);
		nxt[E] = b, cap[E] = 0, flow[E] = 0;
		E++;		
//		cout << "Index " << 2*j+4*N << ": " << a << ' ' << b+N << '\n';
	}
	
	for(int j=0;j<N;j++)
	{
		edges[j+1].push_back(E);
		nxt[E] = j+1+N, cap[E] = INF;
		E++;
		edges[j+1+N].push_back(E);
		nxt[E] = j+1, cap[E] = 0;
		E++;
//		cout << "Index " << 2*j+4*N+M << ": " << j+1 << ' ' << j+1+N << '\n';
	}
	
	if(soldiers2 != soldiers || fflow() != soldiers)
	{
		cout << "NO\n";
		return 0;
	}
	else
	{
		cout << "YES\n";
		for(int i=1;i<=N;i++)
			for(int j=0;j<edges[i].size();j++)
				if(nxt[edges[i][j]] > N)
					travels[i][nxt[edges[i][j]]] += flow[edges[i][j]];
		for(int i=1;i<=N;i++)
		{
			for(int j=N+1;j<=2*N;j++)
				cout << travels[i][j] << ' ';
			cout << '\n';
		}
	}
}