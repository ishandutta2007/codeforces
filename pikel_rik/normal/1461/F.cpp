#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 1e5 + 5;

int n, a[N];
char sign[N];
bool add, mul;

void solve(int l, int r) {
	int prod = 1, sum = 0;
	for (int i = l; i <= r && prod <= 2 * (r - l + 1) + 2; i++) {
		prod *= a[i];
	}

	if (prod > 2 * (r - l + 1) + 2) {
		for (int i = l; i < r && a[i] == 1; i++) {
			sign[i] = '+';
		}
		for (int i = r; i > l && a[i] == 1; i--) {
			sign[i - 1] = '+';
		}
		return;
	}

	vector<pair<int, bool>> segs;
	prod = 1;
	for (int i = l; i <= r; i++) {
		if (a[i] == 1) {
			if (prod > 1) {
				segs.emplace_back(prod, true);
			}
			prod = 1;
			sum++;
		} else {
			if (sum > 0) {
				segs.emplace_back(sum, false);
			}
			sum = 0;
			prod *= a[i];
		}
	}

	if (prod > 1) {
		segs.emplace_back(prod, true);
	} else if (sum > 0) {
		segs.emplace_back(sum, false);
	}

	int best = 0;
	ll best_mask = 0;
	auto recurse = [&](int i, int cur_prod, int ans, ll mask, const auto &self) -> void {
		if (i == segs.size()) {
			if (cur_prod > 1) ans += cur_prod;
			if (ans > best) {
				best = ans;
				best_mask = mask;
			}
		} else if (!segs[i].second) {
			self(i + 1, 1, ans + (cur_prod > 1 ? cur_prod : 0) + segs[i].first, mask, self);
			self(i + 1, cur_prod, ans, mask | (1ll << i), self);
		} else {
			self(i + 1, segs[i].first * cur_prod, ans, mask | (1ll << i), self);
		}
	};

	recurse(0, 1, 0, 0, recurse);

	bitset<64> b = best_mask;

	int cur = 0;
	for (int i = l; i < r; i++) {
		if ((a[i] == 1) ^ (a[i + 1] == 1)) {
			sign[i] = b[cur] ^ b[cur + 1] ? '+' : '*';
			cur++;
		} else {
			sign[i] = b[cur] ? '*' : '+';
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	string s;
	cin >> s;

	for (char ch : s) {
		if (ch == '+') add = true;
		if (ch == '*') mul = true;
	}

	if (s.length() == 1 || !mul) {
		if (add && !mul) s.front() = '+';
		for (int i = 0; i < n; i++) {
			cout << a[i];
			if (i + 1 != n) {
				cout << s.front();
			}
		}
		cout << '\n';
		return 0;
	}

	if (add) {
		int last = -1;
		for (int i = 0; i < n; i++) {
			if (a[i] == 0) {
				if (i > 0) sign[i - 1] = '+';
				sign[i] = '+';
				if (last != i - 1) solve(last + 1, i - 1);
				last = i;
			}
		}
		if (last != n - 1) {
			solve(last + 1, n - 1);
		}
	} else {
		for (int i = 0; i < n - 1; i++) {
			if (a[i + 1] == 0) {
				sign[i] = '-';
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << a[i];
		if (i + 1 != n) {
			cout << (sign[i] != 0 ? sign[i] : '*');
		}
	}
	cout << '\n';
	return 0;
}