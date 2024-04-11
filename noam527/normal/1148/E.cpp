#include <bits/stdc++.h>
#define CHECK cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 1e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

int n;
vector<pair<int, int>> a;
vector<int> t;

vector<vector<int>> op;

void work(int i, int j, int d) {
	a[i].first += d;
	a[j].first -= d;
	op.push_back({ a[i].second, a[j].second, d });
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	a.resize(n);
	t.resize(n);
	ll s1 = 0, s2 = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first, a[i].second = i;
		s1 += a[i].first;
	}
	for (auto &i : t) cin >> i, s2 += i;
	if (s1 != s2) finish("NO");
	
	sort(a.begin(), a.end());
	sort(t.begin(), t.end());
	for (int i = 0; i < n; i++) a[i].first -= t[i];
	vector<int> p, q;
	for (int i = 0; i < n; i++) {
		if (a[i].first > 0) p.push_back(i);
		if (a[i].first < 0) q.push_back(i);
	}
	if (OO) {
		for (const auto &i : a) cout << i.first << " " << i.second << '\n';
		cout << '\n';
		for (const auto &i : q) cout << i << " "; cout << '\n';
		for (const auto &i : p) cout << i << " "; cout << '\n';
	}
	int nxt = 0;
	for (const auto &i : q) {
		while (a[i].first < 0) {
			if (OO) cout << i << " " << p[nxt] << '\n';
			while (a[p[nxt]].first == 0) nxt++;
			if (OO) cout << i << " " << p[nxt] << '\n' << '\n';
			if (p[nxt] < i) finish("NO");
			int mn = min(-a[i].first, a[p[nxt]].first);
			work(i, p[nxt], mn);
		}
	}
	cout << "YES\n";
	cout << op.size() << '\n';
	for (const auto &i : op) cout << 1 + i[0] << " " << 1 + i[1] << " " << i[2] << '\n';
}