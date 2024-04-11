#include <bits/stdc++.h>
#include <random>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>
#define ld long double
#define ull unsigned long long

using namespace std;

const int nax = (1 << 21) + 5;
vector<pii> s[nax];
int n, k;
int a[nax];

struct edge
{
	int to, flow, cap, cost, rev;
};


int counter = 0;
int id[nax];

struct MinCostMaxFlow
{
	int nodes;
	vector<int> prio, curflow, prevedge, prevnode, q, pot;
	vector<bool> inqueue;
	vector<vector<edge> > graph;
	MinCostMaxFlow() {}

	MinCostMaxFlow(int n): nodes(n), prio(n, 0), curflow(n, 0),
	prevedge(n, 0), prevnode(n, 0), q(n, 0), pot(n, 0), inqueue(n, 0), graph(n) {}

	void addEdge(int source, int to, int capacity, int cost)
	{
	    counter++;
		edge a = {to, 0, capacity, cost, (int)graph[to].size()};
		edge b = {source, 0, 0, -cost, (int)graph[source].size()};
		graph[source].push_back(a);
		graph[to].push_back(b);
	}

	void bellman_ford(int source, vector<int> &dist)
	{
		fill(dist.begin(), dist.end(), INT_MAX);
		dist[source] = 0;
		int qt=0;
		q[qt++] = source;
		for(int qh=0;(qh-qt)%nodes!=0;qh++)
		{
			int u = q[qh%nodes];
			inqueue[u] = false;
			for(auto &e : graph[u])
			{
				if(e.flow >= e.cap)
					continue;
				int v = e.to;
				int newDist = dist[u] + e.cost;
				if(dist[v] > newDist)
				{
					dist[v] = newDist;
					if(!inqueue[v])
					{
						inqueue[v] = true;
						q[qt++ % nodes] = v;
					}
				}
			}
		}
	}

	pair<int, int> minCostFlow(int source, int dest, int maxflow)
	{
		bellman_ford(source, pot);
		int flow = 0;
		int flow_cost = 0;
		while(flow < maxflow)
		{
			priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
			q.push({0, source});
			fill(prio.begin(), prio.end(), INT_MAX);
			prio[source] = 0;
			curflow[source] = INT_MAX;
			while(!q.empty())
			{
				int d = q.top().first;
				int u = q.top().second;
				q.pop();
				if(d != prio[u])
					continue;
				for(int i=0;i<graph[u].size();i++)
				{
					edge &e=graph[u][i];
					int v = e.to;
					if(e.flow >= e.cap)
						continue;
					int newPrio = prio[u] + e.cost + pot[u] - pot[v];
					if(prio[v] > newPrio)
					{
						prio[v] = newPrio;
						q.push({newPrio, v});
						prevnode[v] = u;
						prevedge[v] = i;
						curflow[v] = min(curflow[u], e.cap - e.flow);
					}
				}
			}
			if(prio[dest] == INT_MAX)
				break;
			for(int i=0;i<nodes;i++)
				pot[i]+=prio[i];
			int df = min(curflow[dest], maxflow - flow);
			flow += df;
			for(int v=dest;v!=source;v=prevnode[v])
			{
				edge &e = graph[prevnode[v]][prevedge[v]];
				e.flow += df;
				graph[v][e.rev].flow -= df;
				flow_cost += df * e.cost;
			}
		}
		return {flow, flow_cost};
	}
};

int realValue[nax];

void solve(){
    cin >> n >> k;
    for(int i=0;i<(1<<n);i++){
        cin >> a[i];
    }
    vector<int> values;
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            int from = i;
            int to = (from ^ (1 << j));
            if(from < to) continue;
            values.pb(a[from] + a[to]);
        }
    }
    int want = min((int)values.size(), n * k * 2 + 5);
    nth_element(values.begin(), values.end() - want, values.end());
    int barrier = values[(int)values.size() - want];
    int bigger = 0;
    int eq = 0;

    for(int x : values){
        if(x > barrier) bigger++;
    }
    eq = want - bigger;
    set<int> uni;
    vector<pair<int, pii> > edges;
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            int from = i;
            int to = (from ^ (1 << j));
            if(to < from) continue;
            int v = a[from] + a[to];
            if(v > barrier || (v == barrier && eq)){
                if(v == barrier) eq--;
                pii cur = mp(from, to);
                pii now = cur;
                if(__builtin_popcount(now.st) & 1) now = mp(cur.nd, cur.st);
                edges.pb(mp(v, now));
                uni.insert(now.st);
                uni.insert(now.nd);
            }
        }
    }
    want = min((int)values.size(), n * k * 2 + 5);
    MinCostMaxFlow flow(nax + 5);
    int source = nax + 2;
    int sink = nax + 3;
    for(int i=0;i<(1<<n);i++){
        if(uni.count(i) == 0) continue;
        if(__builtin_popcount(i) % 2 == 0){
            flow.addEdge(source, i, 1, 0);
        }
        else flow.addEdge(i, sink, 1, 0);
    }

    for(auto e : edges){
        flow.addEdge(e.nd.st, e.nd.nd, 1, -e.st);
    }
    auto result = flow.minCostFlow(source, sink, k);
    cout << -result.nd << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    // cin >> tt;
    while(tt--) solve();

    return 0;
}