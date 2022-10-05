#include <bits/stdc++.h>
#define CHECK cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 9e18;
const int OO = 0;
using namespace std;

struct trie {
	const int B = 29;
	int n;
	vector<int> to[2];
	trie() {
		n = 1;
		to[0].clear(), to[1].clear();
		to[0].push_back(-1);
		to[1].push_back(-1);
	}
	void clear() {
		n = 1;
		to[0].clear(), to[1].clear();
		to[0].push_back(-1);
		to[1].push_back(-1);
	}
	void add(int val) {
		int v = 0;
		for (int b = B; b >= 0; b--) {
			if (to[val >> b & 1][v] == -1) {
				to[val >> b & 1][v] = n++;
				to[0].push_back(-1);
				to[1].push_back(-1);
			}
			v = to[val >> b & 1][v];
		}
	}
	int mn(int val) {
		int v = 0, ans = 0;
		for (int b = B; b >= 0; b--) {
			if (to[val >> b & 1][v] != -1) v = to[val >> b & 1][v];
			else v = to[val >> b & 1 ^ 1][v], ans += (1 << b);
		}
		return ans;
	}
};

trie T;

ll calc(vector<int> &a, int l, int r, int b) {
	if (l + 1 == r) return 0;
	int mid = l;
	while (mid < r && (a[mid] & (1 << b)) == 0) mid++;
	if (OO) cout << "l r b mid " << l << " " << r << " " << b << " " << mid << '\n';
	if (b == 0) {
		if (mid == l || mid == r) return 0;
		return 1;
	}
	if (mid == l) return calc(a, mid, r, b - 1);
	if (mid == r) return calc(a, l, mid, b - 1);

	ll rtn = calc(a, l, mid, b - 1) + calc(a, mid, r, b - 1);
	T.clear();
	for (int i = l; i < mid; i++) T.add(a[i]);
	int mn = (1 << 30);
	for (int i = mid; i < r; i++)
		mn = min(mn, T.mn(a[i]));
	if (OO) cout << "l r b mid " << l << " " << r << " " << b << " " << mid << '\n';
	if (OO) cout << "adding mn = " << mn << '\n';
	return rtn + mn;
}

int n;
vector<int> a;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	a.resize(n);
	for (auto &i : a) cin >> i;
	sort(a.begin(), a.end());
	cout << calc(a, 0, n, 29) << '\n';
}