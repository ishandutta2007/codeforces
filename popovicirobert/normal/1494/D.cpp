#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "
 
 
using namespace std;

struct DSU {
	vector<int> par;
	int n;

	DSU(int n = 0) : n(n) {
		par.resize(n + 1);
	}

	int root(int x) {
		return (par[x] == 0 ? x : par[x] = root(par[x]));
	}

	void join(int x, int y) {
		x = root(x), y = root(y);
		if (x != y) {
			par[x] = y;
		}
	}
};


int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
		
    int n;
    cin >> n;

    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    vector<pair<int, int>> order;

    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= n; j++) {
    		cin >> a[i][j];
    		if (i < j) {
    			order.push_back({i, j});
    		}
    	}
    }

    sort(order.begin(), order.end(), [&](const pair<int, int>& x, const pair<int, int>& y) {
    	if (a[x.first][x.second] == a[y.first][y.second]) return x < y;
    	return a[x.first][x.second] < a[y.first][y.second];
    });

    vector<int> values(2 * n + 1);
    for (int i = 1; i <= n; i++) {
    	values[i] = a[i][i];
    }

    vector<pair<int, int>> edges;
    DSU dsu(2 * n);
    int node_id = n;

    for (auto itr : order) {
    	int x, y;
    	tie(x, y) = itr;

    	int rx = dsu.root(x), ry = dsu.root(y);

    	if (rx == ry) {
    		assert(values[rx] == a[x][y]);
    		continue;
    	}

    	if (values[rx] > values[ry]) {
    		swap(rx, ry);
    	}

    	if (values[ry] == a[x][y]) {
    		edges.emplace_back(rx, ry);
    		dsu.join(rx, ry);
    	} else {
    		node_id++;
    		values[node_id] = a[x][y];

    		edges.emplace_back(rx, node_id);
    		edges.emplace_back(ry, node_id);

    		dsu.join(rx, node_id);
    		dsu.join(ry, node_id);
    	}
    }

    cout << node_id << "\n";
    for (int i = 1; i <= node_id; i++) {
    	cout << values[i] << " ";
    }
    cout << "\n" << node_id << "\n";
    for (auto edge : edges) {
    	cout << edge.first << " " << edge.second << "\n";
    }
    

    return 0;
}