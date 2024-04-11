#include <bits/stdc++.h>

using namespace std;

struct number_t {
	int a[16];
	number_t() {
		memset(a, 0, sizeof a);
	}
	number_t operator*(const number_t &rhs) const {
		number_t z;
		for (int i = 0; i < 16; ++i)
			z.a[i] = a[i] + rhs.a[i];
		return z;
	}
	number_t& operator*= (const number_t &rhs) {
		for (int i = 0; i < 16; ++i)
			a[i] += rhs.a[i];
		return *this;
	}
	bool operator==(const number_t &rhs) const {
		for (int i = 0; i < 16; ++i)
			if (a[i] != rhs.a[i])
				return false;
		return true;
	}
};

void solve() {
	int m;
	cin >> m;
	vector<pair<int, int>> primes;
	number_t I;
	vector<number_t> aa(m);
	for (int i = 0; i < m; ++i) {
		int b;
		cin >> b;
		primes.emplace_back(b, i);
	}
	sort(primes.begin(), primes.end(), greater<pair<int, int>>());
	for (int i = 0; i < m; ++i) {
		aa[i].a[primes[i].second] = 1;
	}
	if (primes[0].first >= 4) {
		cout << "-1\n";
		return;
	}
	if (m >= 2 && primes[1].first >= 3) {
		cout << "-1\n";
		return;
	}
	if (m >= 3 && primes[2].first >= 2) {
		cout << "-1\n";
		return;
	}
	vector<number_t> base_sol;
	int p = 0;
	bool special = false;
	if (primes[0].first == 3) {
		special = true;
		if (m >= 2 && primes[1].first != 1) {
			cout << "-1\n";
			return;
		}
		number_t a0 = I, a1 = aa[0], a2 = a1 * a1, a3 = a2 * a1;
		base_sol.push_back(a0);
		base_sol.push_back(a3);
		base_sol.push_back(a1);
		base_sol.push_back(a2);
		p = 1;
	}
	else if (primes[0].first == 2) {
		if (m >= 2 && primes[1].first == 2) {
			number_t a = aa[0], b = aa[1];
			base_sol = { I, a*a*b*b, b, a*a*b, b*b, a*b, a*a, a*b*b, a };
			p = 2;
		}
		else {
			number_t a = aa[0];
			base_sol = {I, a*a, a};
			p = 1;
		}
		if (p < primes.size()) {
			vector<number_t> new_sol;
			number_t c = aa[p];
			for (int i = 0; i < base_sol.size(); ++i) {
				if (i > 0 && i % 2 == 0) {
					new_sol.push_back(base_sol[i] * c);
				}
				else {
					new_sol.push_back(base_sol[i]);
				}
			}
			for (int i = 0; i < base_sol.size(); ++i) {
				if (!(i > 0 && i % 2 == 0)) {
					new_sol.push_back(base_sol[i] * c);
				}
				else {
					new_sol.push_back(base_sol[i]);
				}
			}
			base_sol = new_sol;
			++p;
		}
	}
	else if (primes[0].first == 1) {
		base_sol.push_back(I);
		base_sol.push_back(aa[0]);
		p = 1;
		special = true;
	}
	/*
	printf("before anything\n", p);
	for (int i = 0; i < base_sol.size(); ++i) {
		for (int j = 0; j < m; ++j) {
			printf("%d%c", base_sol[i].a[j],  " \n"[j + 1 == m]);
		}
	}
			printf("\n");
			*/
	if (p < primes.size()) {
		number_t a = aa[0], b = aa[1];
		if (special) {
			while (p < primes.size()) {
				vector<number_t> new_sol;
				int n = base_sol.size();
				auto x = aa[p];
				for (int i = 0; i < n; ++i) {
					new_sol.push_back(base_sol[i]);
				}
				for (int i = 0; i < n; ++i) {
					new_sol.push_back(base_sol[i]);
				}
				for (int i = 0; i < n; i += 2) {
					new_sol[i + 1] *= x;
					new_sol[i + n] *= x;
				}
				swap(new_sol[n / 2], new_sol[n]);
				base_sol = new_sol;
				++p;
			}
		}
		else {
			while (p < primes.size()) {
				vector<number_t> new_sol;
				int n = base_sol.size();
				auto x = aa[p];
				for (int i = 0; i < n; ++i) {
					new_sol.push_back(base_sol[i]);
				}
				for (int i = 0; i < n; ++i) {
					new_sol.push_back(base_sol[i]);
				}
				for (int i = n % 2; i < n; i += 2) {
					new_sol[i + 1] *= x;
					new_sol[i + n] *= x;
				}
				if (n % 2) new_sol[n] *= x;
				else swap(new_sol[n], new_sol[2 * n - 1]);
				base_sol = new_sol;
				++p;
			}
		}
	}
	//printf("\n");
	for (int i = 1; i < base_sol.size(); ++i) {
		for (int j = 0; j < m; ++j) {
			cout << base_sol[i].a[j] << " \n"[j + 1 == m];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}