#include <bits/stdc++.h>
        
using namespace std;
        
        
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
        
//#define GCC optimize("O3, Ofast")
//#define GCC optimize("unroll-loops")
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
        
const int inf = 5e9 + 7;
const int max_n = 1e5 + 3;

int n;
vector<int> gr[max_n];
int sz[max_n];

void build_sz(int v, int pr = -1) {
	sz[v] = 1;
	for(int to : gr[v])
		if (to != pr) build_sz(to, v), sz[v] += sz[to];
}

int find_centroid(int v, int pr, int siz) {
	for(int to : gr[v]) {
		if (to != pr && sz[to] * 2 > siz) return find_centroid(to, v, siz);
	}
	return v;
}

vector<vector<int>> ver;


int dfs(int v, int pr = -1) {
	int r = (pr == -1 ? 0 : sz[v]);
	for(int to : gr[v]) {
		if (pr == -1) ver.emplace_back(vector<int>());
		if (to != pr) r += dfs(to, v);
	}
	if (pr != -1) ver[sz(ver) - 1].emplace_back(v);
	return r;
}

void solve() {
	cin >> n;
	for(int i = 0;i < n - 1;i++) {
		int v1, v2;
		cin >> v1 >> v2;
		gr[--v1].emplace_back(--v2);
		gr[v2].emplace_back(v1);
	}

	build_sz(0);
	int root = find_centroid(0, -1, sz[0]);
	build_sz(root);

	cout << 2 * dfs(root) << endl;

	ver.emplace_back(vector<int>{root});

	int firs = -1, firs_id = -1;

	auto comp = [&](int v1, int v2) {
		return mp(sz(ver[v1]), (firs_id == v1 ? inf : v1)) > mp(sz(ver[v2]), (firs_id == v2 ? inf : v2));
	};

	set<int, decltype(comp)> b(comp);
	for(int i = 0;i < sz(ver);i++)
		b.emplace(i);

	auto f = [&](int x) {
		int r = ver[x].back();
		b.erase(x);
		ver[x].pop_back();
		b.emplace(x);
		return r;
	};


	/*for(auto i1 : ver)
		for(auto i2 : i1)
			cout << i2 + 1 << " \n"[i2 == i1.back()];

	cout << endl;*/

	vector<int> res(n);

	int id = *b.begin();
	int id_x = f(id);

	b.erase(id);
	
	firs = id_x;
	firs_id = id;

	b.emplace(id);

	//cout << id << endl;

	while(true) {
		int to_id = *b.begin();

		if (to_id == id) to_id = *(++b.begin());


		if (ver[to_id].empty()) break;

		int to_id_x = f(to_id);

		//cout << to_id << endl;

		res[id_x] = to_id_x;
		id = to_id, id_x = to_id_x;
	}

	res[id_x] = firs;

	for(int i : res)
		cout << i + 1 << " ";
	cout << endl;
}



signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    solve();
}