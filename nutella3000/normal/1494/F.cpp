//  Clash Royale, [11.03.21 11:10]
#include <bits/stdc++.h>

using namespace std;


mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

#define aidar asadulin

#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define pip pair<int, pii>
#define all(b) b.begin(), b.end()
#define fi first
#define se second
#define size(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld double

const int inf = 1e9 + 7;
const int max_n = 3e3 + 3;

int n;
set<int> gr[max_n];
vector<int> res;

vector<int> path;



void euler(int v) {
	while(size(gr[v])) {
		int to = *gr[v].begin();
		gr[v].erase(gr[v].begin()), gr[to].erase(v);

		euler(to);
	}
	path.emplace_back(v);
}

bool g(int st, int fin) {
	vector<set<int>> g(n);
	for(int i = 0;i < n;i++)
		g[i] = gr[i];

	path.clear();
	euler(st);

	bool bad = false;
	for(int i = 0;i < n;i++) {
		if (size(gr[i])) bad = true;
		gr[i] = g[i];
	}
	if (bad) return false;

	if (path.front() != fin) return false;
	return true;
}

bool f(int root) {
	int id = root, cnt = 0;
	for(int i = 0;i < n;i++) {
		if (i == root || gr[i].count(root)) continue;
		if (size(gr[i]) % 2 == 1) {
			cnt++;
			id = i;
		}
	}

	if (cnt >= 2) return false;

	set<int> ch;

	for(int to : gr[root]) {
		if (size(gr[to]) % 2 == 1) ch.emplace(to);
	}
	for(int to : ch) {
		gr[root].erase(to), gr[to].erase(root);
	}

	bool bad = true;
	if (cnt == 0) {
		if (!g(root, root)) {
			set<int> q = ch;
			for(int to : q) {
				gr[root].emplace(to), gr[to].emplace(root);
				ch.erase(to);

				if (g(to, root)) {
					bad = false;
					break;
				}

				ch.emplace(to);
				gr[root].erase(to), gr[to].erase(root);
			}
		}else bad = false;
	}else {
		if (g(id, root)) bad = false;
	}
	if (bad) {
		for(int i : ch)
			gr[root].emplace(i), gr[i].emplace(root);
		return false;
	}

	reverse(all(path));
	path.emplace_back(-2);
	for(int i : ch) {
		path.emplace_back(i);
		path.emplace_back(root);
	}

	return true;
}

void scan() {
	int m;
	cin >> n >> m;
	for(int i = 0;i < m;i++) {
		int v1, v2;
		cin >> v1 >> v2;
		gr[--v1].emplace(--v2);
		gr[v2].emplace(v1);
	}
}

void solve() {
	scan();

	for(int root = 0;root < n;root++) {
		if (f(root)) {
			cout << size(path) << endl;
			for(int i : path)
				cout << i + 1 << " ";
			cout << endl;
			return;
		}
	}
	cout << 0;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    solve();
}