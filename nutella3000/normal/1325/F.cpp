#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
  
using namespace std;
const int inf = 1e9 + 7;
const int max_n = 1e5 + 3;
int n, sqr;
vector<int> gr[max_n];
bool kil[max_n];
int deep[max_n];
int deg[max_n];


/*struct comp {
	bool operator()(int v1, int v2) {
		if (deg[v1] == deg[v2]) return v1 < v2;
		return deg[v1] < deg[v2];
	}
};*/

auto comp = [](int v1, int v2){
	if (deg[v1] == deg[v2]) return v1 < v2;
	return deg[v1] < deg[v2];
};

set<int, decltype(comp)> sorted(comp);


void scan() {
	int m;
	cin >> n >> m;

	for(int i = 0;i < m;i++) {
		int v1, v2;
		cin >> v1 >> v2;
		v1--; v2--;
		gr[v1].emplace_back(v2);
		gr[v2].emplace_back(v1);
		deg[v1]++;
		deg[v2]++;
	}

	for(int i = 0;i < n;i++) sorted.emplace(i);
}

vector<int> res2, res1;
int real_size = 0;


bool dfs(int v, int d) {
	deep[v] = d;
	for(int to : gr[v]) {
		if (kil[to]) continue;
		if (deep[to] != 0) {
			if (deep[v] - deep[to] + 1 >= sqr) {
				real_size = deep[v] - deep[to] + 1;
				res2.emplace_back(v);
				return true;
			}
		}else {
			dfs(to, d + 1);
			if (res2.size() != real_size) res2.emplace_back(v);
			return true;
		}
	}

	cout << v << " " << d << endl;

	while(true);
}

void solve() {
	scan();
	sqr = ceil(sqrt(n));
	//cout << sqr << '\n';

	while(res1.size() < sqr && res2.size() < sqr) {
		if (deg[*sorted.begin()] >= sqr - 1) {
			for(int v = 0;v < n;v++) {
				if (kil[v]) continue;
				dfs(v, 1);
				break;
			}
		}else{
			int v = *sorted.begin();
			res1.emplace_back(v);
			sorted.erase(v);
			kil[v] = true;
			for(int to : gr[v]) {
				if (kil[to]) continue;
				kil[to] = true;
				sorted.erase(to);
				for(int to_to : gr[to]) {
					if (sorted.find(to_to) == sorted.end()) continue;

					sorted.erase(to_to);
					deg[to_to]--;
					sorted.emplace(to_to);
				}

			}
		}
	}

	if (res1.size() >= sqr) {
		cout << 1 << '\n';
		for(int i : res1) cout << i + 1 << " ";
	}else {
		cout << 2 << '\n';
		cout << res2.size() << '\n';
		for(int i : res2) cout << i + 1 << " ";
	}
}


 
signed main() {
/*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif*/
 
    solve();
}