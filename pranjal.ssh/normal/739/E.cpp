#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(int i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}

const double InfCost = 1e9;
struct MinimumCostMaximumFlow {
	typedef int Index; typedef int Flow; typedef double Cost;
	static const Flow InfCapacity = 1e9 + 7;
	struct Edge {
		Index to; Index rev;
		Flow capacity; Cost cost;
	};
	vector<vector<Edge> > g;
	void init(Index n) { g.assign(n, vector<Edge>()); }
	void add(Index i, Index j, Flow capacity = InfCapacity, Cost cost = Cost()) {
		// cout<<i<<" "<<j<<" "<<capacity<<" "<<cost<<"\n";
		Edge e, f; e.to = j, f.to = i; e.capacity = capacity, f.capacity = 0; e.cost = cost, f.cost = -cost;
		g[i].push_back(e); g[j].push_back(f);
		g[i].back().rev = (Index)g[j].size() - 1; g[j].back().rev = (Index)g[i].size() - 1;
	}
	void addB(Index i, Index j, Flow capacity = InfCapacity, Cost cost = Cost()) {
		add(i, j, capacity, cost);
		add(j, i, capacity, cost);
	}
	pair<Cost, Flow> minimumCostMaximumFlow(Index s, Index t, Flow f = InfCapacity, bool bellmanFord = false) {
		int n = g.size();
		vector<Cost> dist(n); vector<Index> prev(n); vector<Index> prevEdge(n);
		pair<Cost, Flow> total = make_pair(0, 0);
		vector<Cost> potential(n);
		while (f > 0) {
			fill(dist.begin(), dist.end(), InfCost);
			if (bellmanFord || total.second == 0) {
				dist[s] = 0;
				for (int k = 0; k < n; k++) {
					bool update = false;
					for (int i = 0; i < n; i++)
						if (dist[i] != InfCost)
							for (Index ei = 0; ei < (Index)g[i].size(); ei ++) {
								const Edge &e = g[i][ei];
								if (e.capacity <= 0) continue;
								Index j = e.to; Cost d = dist[i] + e.cost;
								if (dist[j] > d ) { //
									dist[j] = d; prev[j] = i; prevEdge[j] = ei;
									update = true;
								}
							}
					if (!update) break;
				}
			} else {
				vector<bool> vis(n);
				priority_queue<pair<Cost, Index> > q;
				q.push(make_pair(-0, s)); dist[s] = 0;
				while (!q.empty()) {
					Index i = q.top().second; q.pop();
					if (vis[i]) continue;
					vis[i] = true;
					for (Index ei = 0; ei < (Index)g[i].size(); ei ++) {
						const Edge &e = g[i][ei];
						if (e.capacity <= 0) continue;
						Index j = e.to; Cost d = dist[i] + e.cost + potential[i] - potential[j];
						if (d < dist[i])  d = dist[i];   //
						if (dist[j] > d) {
							dist[j] = d; prev[j] = i; prevEdge[j] = ei;
							q.push(make_pair(-d, j));
						}
					}
				}
			}
			if (dist[t] == InfCost) break;
			if (!bellmanFord) for (Index i = 0; i < n; i ++) potential[i] += dist[i];
			Flow d = f; Cost distt = 0;
			for (Index v = t; v != s; ) {
				Index u = prev[v]; const Edge &e = g[u][prevEdge[v]];
				d = min(d, e.capacity); distt += e.cost; v = u;
			}
			f -= d; total.first += d * distt; total.second += d;
			for (Index v = t; v != s; v = prev[v]) {
				Edge &e = g[prev[v]][prevEdge[v]];
				e.capacity -= d; g[e.to][e.rev].capacity += d;
			}
		}
		return total;
	}
};
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n, a, b; cin >> n >> a >> b;
	MinimumCostMaximumFlow G;
	G.init(n + 4);
	int src = n, srca = n + 1, srcb = n + 2, sink = n + 3;
	vector<double> p(n), u(n);
	FOR (i, 0, n - 1) cin >> p[i];
	FOR (i, 0, n - 1) cin >> u[i];

	G.add(src, srca, a, 0);
	G.add(src, srcb, b, 0);
	FOR (i, 0, n - 1) {
		G.add(srca, i, 1, -p[i]);
		G.add(srcb, i, 1, -u[i]);
		G.add(i, sink, 1, 0);
		G.add(i, sink, 1, p[i]*u[i]);
	}
	cout << fixed << setprecision(10) << -G.minimumCostMaximumFlow(src, sink, 1e6, 0).first << "\n";

	return 0;
}