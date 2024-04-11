#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
//#define endl '\n'
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

void pick(int v) {
	cout << v << endl;
	fflush(stdout);
	cout.flush();
}
int gett() {
	int v;
	cin >> v;
	return v;
}

int n, m, t;
vector<int> p;
vector<int> can;
vector<int> with;
vector<pair<int, int>> a;

int main() {
	fast;
	cin >> n >> m;
	n *= 2;
	p.resize(n + 1);
	can.resize(n + 1, 1);
	with.resize(n + 1, -1);
	a.resize(m);
	for (int i = 1; i <= n; i++) cin >> p[i];
	for (int i = 0; i < m; i++) cin >> a[i].first >> a[i].second;
	for (auto &i : a) with[i.first] = i.second, with[i.second] = i.first;
	cin >> t;

	int last = -1;
	bool found;

	for (int i = 0; i < n; i++) {
		if (t == 1) {
			found = false;
			for (const auto &j : a) {
				if (last == j.first && can[j.second]) {
					found = true;
					pick(j.second);
					can[j.second] = 0;
				}
				if (last == j.second && can[j.first]) {
					found = true;
					pick(j.first);
					can[j.first] = 0;
				}
			}
			if (!found) {
				for (const auto &j : a)
					if (can[j.first] && !found) {
						if (p[j.first] > p[j.second]) {
							found = true;
							pick(j.first);
							can[j.first] = 0;
						}
						else {
							found = true;
							pick(j.second);
							can[j.second] = 0;
						}
					}
			}
			if (!found) {
				int mx = -1, mn = inf, pos = -1;
				for (int j = 1; j <= n; j++) {
					if (can[j]) {
						
						if (with[j] == -1) {
							if (mx < p[j]) {
								mx = p[j];
								pos = j;
							}
						}
						else {
							if (mx < p[j] - p[with[j]]) {
								mx = p[j] - p[with[j]];
								pos = j;
							}
						}
						/*
						if (mx < p[j]) {
							mx = p[j];
							if (with[j] == -1) mn = -1;
							else mn = p[with[j]];
							pos = j;
						}
						else if (mx == p[j] && (with[j] == -1 ? -1 : p[with[j]]) < mn) {
							mx = p[j];
							if (with[j] == -1) mn = -1;
							else mn = p[with[j]];
							pos = j;
						}
						*/
					}
				}
				pick(pos);
				can[pos] = 0;
			}
		}
		else {
			last = gett();
			can[last] = 0;
		}
		t ^= 3;
	}
}