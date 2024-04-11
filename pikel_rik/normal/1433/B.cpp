#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n);
		for (auto& aa : a) cin >> aa;

		vector<int> pos;
		for (int i = 0; i < n; i++) {
			if (a[i]) {
				pos.push_back(i);
			}
		}
		int gaps = 0;
		for (int i = 1; i < pos.size(); i++) {
			gaps += pos[i] - pos[i - 1] - 1;
		}
		cout << gaps << '\n';
	}
	return 0;
}