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

	int q;
	cin >> q;

	while (q--) {
		int n; ll k;
		cin >> n >> k;

		string s;
		cin >> s;

		vector<int> pos;
		for (int i = 0; i < n; i++) {
			if (s[i] == '0') {
				pos.push_back(i);
			}
		}

		int last = -1;
		for (int i = 0; i < pos.size(); i++) {
			if (pos[i] - i <= k) {
				k -= pos[i] - i;
			} else {
				last = i;
				break;
			}
		}

		if (last != -1) {
			sort(s.begin(), s.begin() + pos[last]);
			for (int j = pos[last]; k; j--) {
				swap(s[j - 1], s[j]);
				k -= 1;
			}
		} else {
			sort(s.begin(), s.end());
		}

		cout << s << '\n';
	}
	return 0;
}