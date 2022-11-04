#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 123;
const int MOD = (int) 1e9 + 7;
const ll LINF = (ll) 1e18 + 123;

#define sz(x) (int) (x).size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define all(x) (x).begin(), (x).end()

void run();

int main() {
	cout << setprecision(15) << fixed;
#ifndef LOCAL
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
#endif
	run();
	return 0;
}

// == BEGIN SOLUTION == //

const int N = 1005;

void NO() {
	cout << "NO\n";
	exit(0);
}

int n;
string a[N], b[N];
map<string, vector<int>> q;
string ans[N];

void run() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s, t;
		cin >> s >> t;
		a[i] = s.substr(0, 3);
		b[i] = s.substr(0, 2) + t.substr(0, 1);
	}
	
	for (int i = 0; i < n; i++) {
		q[a[i]].pb(i);
	}
	
	set<string> all;
	
	for (auto &it : q) {
		vector<int> &w = it.second;
		if (sz(w) > 1) {
			for (int i : w) {
				if (all.count(b[i])) NO();
				all.insert(b[i]);
				ans[i] = b[i];
			}
		}
	}
	
	for (int i = 0; i < n + 1; i++) {
		for (auto &it : q) {
			vector<int> &w = it.second;
			if (sz(w) == 1) {
				int id = w[0];
				if (sz(ans[id])) continue;
				if (all.count(a[id])) {
					ans[id] = b[id];
					if (all.count(b[id])) NO();
					all.insert(b[id]);
				}
			}
		}
	}
	
	for (auto &it : q) {
		vector<int> &w = it.second;
		if (sz(w) == 1) {
			int id = w[0];
			if (sz(ans[id]) == 0) {
				ans[id] = a[id];
				all.insert(a[id]);
			}
		}
	}
	
	if (sz(all) != n) NO();
	
	cout << "YES\n";
	for (int i = 0; i < n; i++) {
		cout << ans[i] << "\n";
	}
}