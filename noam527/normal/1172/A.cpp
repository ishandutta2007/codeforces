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
vector<int> a, b;
set<int> s;
int v[200005];

bool check(int x) {
	for (int i = 1; i <= n; i++) v[i] = 0;
	for (auto &i : a) v[i] = 1;
	int p = n - 1;
	while (x > 0 && p >= 0) {
		if (b[p]) v[b[p]] = 1;
		p--;
		x--;
	}
	if (OO) {
		for (int i = 1; i <= n; i++) cout << v[i] << " "; cout << '\n';
	}
	int nxt = n;
	while (nxt >= 1) {
		if (!v[nxt]) return false;
		v[nxt] = 0;
		nxt--;
		if (p >= 0) {
			if (b[p]) v[b[p]] = 1;
			p--;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	b.resize(n);
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		if (x) a.push_back(n + 1 - x);
	}
	for (auto &i : b) {
		cin >> i;
		if (i) i = n + 1 - i;
	}
	reverse(b.begin(), b.end());
	if (b[0] != 0) {
		int p = 0;
		while (p + 1 < b.size() && b[p] + 1 == b[p + 1]) p++;
		if (p + 1 == b.size()) finish(0);
		if (b[p] == n) {
			s.clear();
			for (auto &i : a) s.insert(i);
			int nxt = b[0] - 1, p = n - 1;
			while (nxt >= 1) {
				auto it = s.find(nxt);
				if (it == s.end()) break;
				s.erase(it);
				if (b[p]) s.insert(b[p]);
				nxt--;
				p--;
			}
			if (nxt == 0) finish(b[0] - 1);
		}
	}
	if (OO) {
		cout << check(7) << '\n';
		return 0;
	}
	int lo = 0, hi = n + 5, mid;
	while (lo < hi) {
		mid = (lo + hi) / 2;
		if (check(mid)) hi = mid;
		else lo = mid + 1;
	}
	finish(lo + n);
}