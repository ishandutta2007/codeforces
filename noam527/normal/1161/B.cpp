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

int n, m;
vector<pair<int, int>> a, b;
vector<int> pos[100005];

void clean(vector<pair<int, int>> &aa) {
	for (auto &i : aa)
		if (i.first > i.second) swap(i.first, i.second);
	sort(aa.begin(), aa.end());
}

bool check(int k) {
	if (OO) cout << "trying " << k << '\n';
	for (int i = 0; i < m; i++)
		b[i] = { (a[i].first + k) % n, (a[i].second + k) % n };

	if (OO) {
		cout << "cleaned b\n";
		for (const auto &i : b) cout << i.first << " " << i.second << '\n';
	}
	clean(b);
	if (OO) {
		cout << "cleaned b\n";
		for (const auto &i : b) cout << i.first << " " << i.second << '\n';
	}
	return a == b;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	a.resize(m);
	b.resize(m);
	for (auto &i : a) cin >> i.first >> i.second, --i.first, --i.second;
	clean(a);
	if (OO) {
		cout << "cleaned a\n";
		for (const auto &i : a) cout << i.first << " " << i.second << '\n';
	}
	for (int k = 1; k * k <= n; k++) {
		if (n % k == 0) {
			if (check(k)) finish("Yes");
			if (k != 1 && check(n / k)) finish("Yes");
		}
	}
	finish("No");
}