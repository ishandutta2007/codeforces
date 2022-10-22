#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

struct Edge {
	int u, v, w;
	int to(int x) {return x==u?v:u;}
} e[200000];

int n, m;
double ans[100000];
bool vis[100000], vis2[200000]; //is vertex visited, is edge visited
vector<int> adj[100000], comp;
set<pair<int, int>> alg[100000]; //pair<a, b> means has value ax+b

void dfs(int u) {
	comp.push_back(u);
	vis[u]=1;
	for (int v: adj[u]) if (!vis2[v]) {
		vis2[v]=1;
		pair<int, int> c=*alg[u].begin();
		int nxt=e[v].to(u);
		alg[nxt].insert({-c.first, e[v].w-c.second});
		if (!vis[nxt]) dfs(nxt);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		int a, b, c; cin >> a >> b >> c, --a, --b;
		e[i].u=a, e[i].v=b, e[i].w=c;
		adj[a].push_back(i);
		adj[b].push_back(i);
	}
	for (int i=0; i<n; ++i) if (!vis[i]) {
		assert(alg[i].empty()); alg[i].insert({1, 0});
		dfs(i);
		double val=-666; //what is val
		for (int u: comp) {
			vector<pair<int, int>> v(alg[u].begin(), alg[u].end());
			//for (auto x: v) cout << x.first << ' ' << x.second << "    ";
			//cout << '\n';
			for (int i=0; i<v.size()-1; ++i) {
				if (v[i].first==v[i+1].first) {
					cout << "NO";
					return 0;
				}
				double cur=(double)(v[i+1].second-v[i].second)/(v[i].first-v[i+1].first);
				if (val!=-666&&abs(cur-val)>1e-8) {
					cout << "NO";
					return 0;
				}
				if (val==-666) val=cur;
			}
		}
		if (val==-666) {
			map<pair<int, int>, int> cnt;
			for (int u: comp) {
				assert(alg[u].size()==1);
				cnt[*alg[u].begin()]++;
			}
			int MX=INT_MAX;
			for (auto x: cnt) {
				pair<int, int> p=x.first;
				int cur=p.second/(-p.first);
				int sum=0;
				for (auto y: cnt)
					sum+=y.second*abs(cur*y.first.first+y.first.second);
				if (sum<MX) {
					MX=sum;
					val=cur;
				}
			}
		}
		assert(val!=-666);
		for (int u: comp) {
			pair<int, int> temp=*alg[u].begin();
			ans[u]=val*temp.first+temp.second;
		}
		comp.clear();
	}
	cout << "YES\n";
	for (int i=0; i<n; ++i) cout << ans[i] << ' ';
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/