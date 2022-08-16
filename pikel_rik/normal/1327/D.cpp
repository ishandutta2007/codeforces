#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

template <typename T>
vector<T> divisors(T n, bool mustSort = false) {
    vector<T> div;
    for (int i = 1; (T)i * i <= n; i++) {
        if (n % i == 0) {
            div.push_back(i);
            if (i != n / i) {
                div.push_back(n / i);
            }
        }
    }
    if (mustSort) {
        sort(div.begin(), div.end());
    }
    return div;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> p(n), c(n);
		for (auto &i : p) cin >> i, --i;
		for (auto &i : c) cin >> i;

		int ans = INT_MAX;

		vector<bool> visited(n);
		for (int i = 0; i < n; i++) {
			if (visited[i]) continue;

			vector<int> cycle = {i};

			int ptr = p[i];
			while (ptr != i) {
				visited[ptr] = true;
				cycle.push_back(ptr);
				ptr = p[ptr];
			}

			int cyc = (int)cycle.size();
			vector<int> div = divisors(cyc);

			for (int d : div) {
				for (int j = 0; j < d; j++) {
					bool ok = true;
					for (int k = j + d; k < cyc; k += d) {
						ok &= c[cycle[k]] == c[cycle[k - d]];
					}
					if (ok) {
						ans = min(ans, d);
					}
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}