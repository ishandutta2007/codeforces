#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l, int r)
{
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}
  
#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

//Push-Relabel Algorithm for Flows, Complexity: O(V^2 E)
//To obtain the actual flow values, look at all edges with capacity > 0
//Zero capacity edges are residual edges

struct edge
{
	int from, to, cap, flow, index;
	edge(int from, int to, int cap, int flow, int index):
		from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct PushRelabel
{
	static const long long INF=1e18;

	int n;
	vector<vector<edge> > g;
	vector<long long> excess;
	vector<int> height;

	PushRelabel(int n):
		n(n), g(n), excess(n), height(n) {}

	void addEdge(int from, int to, int cap)
	{
		g[from].push_back(edge(from, to, cap, 0, g[to].size()));
		if(from==to)
			g[from].back().index++;
		g[to].push_back(edge(to, from, 0, 0, g[from].size()-1));
	}

	void push(edge &e)
	{
	    int amt=(int)min(excess[e.from], (long long)e.cap - e.flow);
		if(height[e.from]<=height[e.to] || amt==0)
			return;
		e.flow += amt;
		g[e.to][e.index].flow -= amt;
		excess[e.to] += amt;
		excess[e.from] -= amt;
	}

	void relabel(int u)
	{
		int d=2e5;
		for(auto &it:g[u])
		{
			if(it.cap-it.flow>0)
				d=min(d, height[it.to]);
		}
		if(d<INF)
			height[u]=d+1;
	}

	vector<int> find_max_height_vertices(int source, int dest)
	{
		vector<int> max_height;
		for(int i=0;i<n;i++)
		{
			if(i!=source && i!=dest && excess[i]>0)
			{
				if(!max_height.empty() && height[i] > height[max_height[0]])
					max_height.clear();
				if(max_height.empty() || height[i] == height[max_height[0]])
					max_height.push_back(i);
			}
		}
		return max_height;
	}

	long long max_flow(int source, int dest)
	{
		excess.assign(n, 0);
		height.assign(n, 0);
		height[source]=n;
		excess[source]=INF;
		for(auto &it:g[source])
			push(it);

		vector<int> current;
		while(!(current = find_max_height_vertices(source, dest)).empty())
		{
			for(auto i:current)
			{
				bool pushed=false;
				for(auto &e:g[i])
				{
					if(excess[i]==0)
						break;
					if(e.cap - e.flow>0 && height[e.from] == height[e.to] + 1)
					{
						push(e);
						pushed=true;
					}
				}
				if(!pushed)
				{
					relabel(i);
					break;
				}
			}
		}

		long long max_flow=0;
		for(auto &e:g[source])
			max_flow+=e.flow;

		return max_flow;
	}
};

void solve()
{
    int n;
    cin >> n;
    
    int a[3];
    int b[3];
    
    f(i,3) cin >> a[i];
    f(i,3) cin >> b[i];
    
    int mx = 0;
    mx = min(a[0],b[1]) + min(a[1],b[2]) + min(a[2],b[0]);
    
    int mn = 0;
    
    PushRelabel go(8);
    go.addEdge(0,1,a[0]);
    go.addEdge(0,2,a[1]);
    go.addEdge(0,3,a[2]);
    go.addEdge(4,7,b[0]);
    go.addEdge(5,7,b[1]);
    go.addEdge(6,7,b[2]);
    go.addEdge(1,4,n);
    go.addEdge(1,6,n);
    go.addEdge(2,5,n);
    go.addEdge(2,4,n);
    go.addEdge(3,6,n);
    go.addEdge(3,5,n);
    
   cout << n - go.max_flow(0,7)<< ' ' <<mx << '\n';
}

signed main()
{
    fast;
    
    int t = 1;
    
   // cin >> t;
    
    while(t--)
        
    solve();
}