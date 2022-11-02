#include <bits/stdc++.h>

using namespace std;


mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

#define aidar asadulin
 
#define int long long
#define ull long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define pip pair<int, pii>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld double

const int inf = 1e18 + 7;
const int max_n = 2e5 + 3;

int n;
vector<pair<pii, int>> gr[max_n][4];
int dist[max_n][4];

vector<int> dijkstra() {
	auto comp = [] (pii v1, pii v2) {
		if (dist[v1.fi][v1.se] == dist[v2.fi][v2.se]) return v1 < v2;
		return dist[v1.fi][v1.se] < dist[v2.fi][v2.se];
	};

	set<pii, decltype(comp)> sort(comp);

	for(int i = 0;i < n;i++) {
		for(int j = 0;j < 4;j++) {
			if (i != 0 || j != 0) dist[i][j] = inf;
		}
	}
	sort.emplace(0, 0);

	while(sz(sort)) {
		pii v = (*sort.begin());
		//cout << "dij " << v.fi + 1 << " " << v.se << " " << dist[v.fi][v.se] << endl;
		sort.erase(sort.begin());

		for(pair<pii, int> to : gr[v.fi][v.se]) {
			if (dist[to.fi.fi][to.fi.se] > dist[v.fi][v.se] + to.se) {
				sort.erase(to.fi);
				dist[to.fi.fi][to.fi.se] = dist[v.fi][v.se] + to.se;
				sort.emplace(to.fi);
			}
		}
	}
	//cout << dist[1][3] << endl;

	vector<int> res(n - 1);
	for(int i = 1;i < n;i++) {
		res[i - 1] = dist[i][3];
	}
	return res;
}

void solve() {
	int m;
	cin >> n >> m;
	for(int it = 0;it < m;it++) {
		int v1, v2, c;
		cin >> v1 >> v2 >> c;
		v1--; v2--; 
		for(int i = 0;i < 4;i++) {
			for(int j = 0;j < 4;j++) {
				if ((j & i) == i) {
					int r = c * (1 - ((j & 1) && !(i & 1)) + ((j & 2) && !(i & 2)));
					gr[v1][i].push_back({{v2, j}, r});
				}
				if ((i & j) == j) {
					int r = c * (1 - ((i & 1) && !(j & 1)) + ((i & 2) && !(j & 2)));
					gr[v2][j].push_back({{v1, i}, r});
				}
			}
		}
	}
	/*for(int i = 0;i < n;i++) {
		for(int j = 0;j < 4;j++) {
			cout << i + 1 << " " << j << ":" << endl;
			for(auto to : gr[i][j]) {
				cout << to.fi.fi + 1 << " " << to.fi.se << " " << to.se << endl;
			}
			cout << endl << endl;
		}
	}*/

	vector<int> res = dijkstra();
	for(int i : res)
		cout << i << " ";
}


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    solve();
}