#include <bits/stdc++.h>
using namespace std;

int a[400005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n;
	cin >> t;
	while (t--) {
		int c = 0, acc = 0, pos = 0;
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		if (n <= 5) {
			cout << "0 0 0\n";
			continue;
		}
		vector<pair<int, int> > v;
		v.reserve(n);
		for (int i = 0; i < n; i++) {
			if (i && a[i] != a[i - 1]) v.emplace_back(a[i - 1], c), c = 0;
			c++;
		}
		v.emplace_back(a[n - 1], c);
		for (auto i : v) {
			if (acc + i.second > n / 2) break;
			pos++;
			acc += i.second;
		}
		if (pos < 3) cout << "0 0 0\n";
		else {
			int ft = v[0].second, snd = (acc - v[0].second - v[pos - 1].second), thrd = v[pos - 1].second;
			pos--;
			while (pos && ft >= thrd) {
				pos--;
				thrd += v[pos].second;
				snd -= v[pos].second;
			}
			if (!pos || ft >= snd) cout << "0 0 0\n";
			else cout << ft << ' ' << snd << ' ' << thrd << '\n';
		}
	}
}