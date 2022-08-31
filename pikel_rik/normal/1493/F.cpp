#include <bits/stdc++.h>
using namespace std;

template<typename T>
std::vector<T> divisors(T n) {
	std::vector<T> divisors;
	for (int i = 1; (T) i * i <= n; i++) {
		if (n % i == 0) {
			divisors.push_back(i);
			if (i != n / i) {
				divisors.push_back(n / i);
			}
		}
	}
	return divisors;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n, m;
	cin >> n >> m;

	int ans = 1;
	for (int rot = 0; rot < 2 ; rot++) {
		auto query = [&](int h, int i1, int j1, int i2, int j2) -> int {
			if (rot == 0)
				cout << "? " << h << ' ' << m << ' ' << i1 + 1 << ' ' << j1 + 1 << ' ' << i2 + 1 << ' ' << j2 + 1 << endl;
			else
				cout << "? " << m << ' ' << h << ' ' << j1 + 1 << ' ' << i1 + 1 << ' ' << j2 + 1 << ' ' << i2 + 1 << endl;
			int t;
			cin >> t;
			return t;
		};

		const bool f1 = n % 2 == 0 && query(n / 2, 0, 0, n / 2, 0);

		auto check = [&](int d) -> bool {
			if (d == n) {
				return true;
			}
			if ((n / d) % 2 == 0) {
				return f1 && (d == n / 2 || query(n / 2 - d, d, 0, n / 2, 0));
			} else {
				int h = (n - d) / 2;
				return query(h , 0, 0, h, 0) && query(h, 0, 0, h + d, 0);
			}
		};

		vector<int> div = divisors(n);
		set<int> remaining(div.begin(), div.end()), taken;

		while (!remaining.empty()) {
			int x = rng() % remaining.size(), q = -1;
			for (auto d : remaining) {
				if (x == 0) {
					q = d;
					break;
				}
				x -= 1;
			}

			if (check(q)) {
				for (int d : divisors(n / q)) {
					remaining.erase(q * d);
					taken.insert(q * d);
				}
			} else {
				for (int d : divisors(q)) {
					remaining.erase(d);
				}
			}

			while (true) {
				set<int> new_taken;
				for (auto d1 : taken) {
					for (auto d2 : taken) {
						if (remaining.erase(__gcd(d1, d2))) {
							new_taken.insert(__gcd(d1, d2));
						}
					}
				}
				if (new_taken.empty())
					break;
				for (int d : new_taken) {
					taken.insert(d);
				}
			}
		}
		ans *= taken.size();
		swap(n, m);
	}
	cout << "! " << ans << endl;
	return 0;
}