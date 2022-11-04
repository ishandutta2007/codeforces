#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "

using namespace std;

const int MAXN = (int) 1e5;

vector<int> g[MAXN + 1];
int w[MAXN + 1];

void dfs(int nod, int par) {
	w[nod] = 1;
	for(auto it : g[nod]) {
		if(it != par) {
			dfs(it, nod);
			w[nod] += w[it];
		}
	}
}

vector<vector<int>> nodes;

struct Data {
	int id;
	bool operator <(const Data &other) const {
		return nodes[id].size() < nodes[other.id].size();
	}
};


int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

 	cin >> n;

 	for(i = 1; i < n; i++) {
 		int x, y;
 		cin >> x >> y;
 		g[x].push_back(y);
 		g[y].push_back(x);
 	}

 	dfs(1, 0);

 	int root = 0;
 	for(i = 1; i <= n; i++) {
 		int mx = 0;
 		for(auto it : g[i]) {
 			int cur = w[it];
 			if(cur > w[i]) {
 				cur = n - w[i];
 			}
 			mx = max(mx, cur);
 		}
 		if(mx <= n / 2) {
 			root = i;
 			break;
 		}
 	}

 	assert(root != 0);

 	priority_queue<Data> pq;
 	ll ans = 0;

 	for(auto it : g[root]) {
 		nodes.push_back(vector<int>());

 		function<void(int, int, vector<int>&, ll&, int)> dfs1 = [&](int nod, int par, vector<int>& nodes, ll& ans, int lvl) {
 			nodes.push_back(nod);
 			ans += 2 * lvl;
 			for(auto it : g[nod]) {
 				if(it != par) {
 					dfs1(it, nod, nodes, ans, lvl + 1);
 				}
 			}
 		};

 		dfs1(it, root, nodes.back(), ans, 1);
 		pq.push({(int)nodes.size() - 1});
 	}

 	/*for(i = 0; i < (int)nodes.size(); i++) {
 		for(auto it : nodes[i]) {
 			cerr << it << " ";
 		}
 		cerr << "\n";
 	}*/

 	vector<int> sol(n + 1);
 	int num = n - 1;

 	while(num > 2) {
 		int a = pq.top().id;
 		pq.pop();
 		int nodA = nodes[a].back();
 		nodes[a].pop_back();

 		int b = pq.top().id;
 		pq.pop();
 		int nodB = nodes[b].back();
 		nodes[b].pop_back();

 		if(a != b) {
 			pq.push({a});
 		}
 		pq.push({b});

 		sol[nodA] = nodB;
 		sol[nodB] = nodA;

 		num -= 2;
 	}

 	if(num == 1) {
 		int a = pq.top().id;
 		sol[root] = nodes[a].back();
 		sol[nodes[a].back()] = root;
 	}
 	else {
 		int a = pq.top().id;
 		pq.pop();
 		int nodA = nodes[a].back();
 		nodes[a].pop_back();
 		pq.push({a});
 		
 		int b = pq.top().id;
 		int nodB = nodes[b].back();

 		sol[root] = nodA;
 		sol[nodA] = nodB;
 		sol[nodB] = root;
 	}

 	cout << ans << "\n";
 	for(i = 1; i <= n; i++) {
 		cout << sol[i] << " ";
 	}

    return 0;
}