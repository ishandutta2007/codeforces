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
      
const int inf = 1e15 + 7;
const int max_n = 2e5 + 3;

int n[4];
int a[4][max_n];
set<int> bad[4][max_n];
set<pii> b[4];

int dfs(int it, int v) {
	//cout << it + 1 << " " << v + 1<< endl;
	if (it == 3) return a[it][v];
	vector<pii> q;
	int res = inf;
	for(auto i : b[it + 1]) {
		if (!bad[it][v].count(i.se)) {
			chkmin(res, dfs(it + 1, i.se));
			q.emplace_back(i);
		}
	}
	for(auto i : q)
		b[it + 1].erase(i);

	return res + a[it][v];
}


void solve() {
	cin >> n[0] >> n[1] >> n[2] >> n[3];
	for(int i = 0;i < 4;i++) {
		for(int j = 0;j < n[i];j++)
			cin >> a[i][j];
	}

	for(int i = 0;i < 3;i++) {
		int m;
		cin >> m;
		for(int j = 0;j < m;j++) {
			int v1, v2;
			cin >> v1 >> v2;
			v1--; v2--;
			bad[i][v1].emplace(v2);
		}
	}

	for(int i = 0;i < 4;i++) {
		for(int j = 0;j < n[i];j++) {
			b[i].emplace(a[i][j], j);
		}
	}

	int res = inf;
	while(sz(b[0])) {
		int v = (b[0].begin()->se);
		b[0].erase(b[0].begin());
		chkmin(res, dfs(0, v));
	}

	cout << (res == inf ? -1 : res) << endl;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    solve();
}