#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 998244353;
const double pi = acos(-1.0);
const int inf = INT_MAX;

template <typename T>
bool isPrime(T x) {
    if (x == 1) {
        return false;
    }
    for (int i = 2; (T)i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<vector<int>> a(n, vector<int>(n, 1));
		for (int i = n;; i++) {
			if (isPrime(i) && !isPrime(1 + i - n)) {
				for (int j = 0; j < n; j++) {
					a[j][j] += i - n;
				}
				break;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << a[i][j] << ' ';
			}
			cout << '\n';
		}
	}
	return 0;
}