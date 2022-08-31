#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	vector<int> rev(256, -1);
	rev[0] = 0, rev[1] = 1;
	rev[2] = 5, rev[5] = 2;
	rev[8] = 8;

	auto reverse_num = [&](int x) -> int {
		int f = x / 10, s = x % 10;
		if (rev[f] == -1 || rev[s] == -1)
			return -1;
		return rev[s] * 10 + rev[f];
	};

	auto convert = [&](int x) -> string {
		return to_string(x / 10) + to_string(x % 10);
	};

	while (t--) {
		int h, m;
		cin >> h >> m;

		string s;
		cin >> s;

		int hh = stoi(s.substr(0, 2));
		int mm = stoi(s.substr(3));

		string ans;
		while (ans.empty()) {
			int now_mm = reverse_num(hh), now_hh = reverse_num(mm);
			if (now_mm != -1 && now_hh != -1 && now_mm < m && now_hh < h) {
				ans = convert(hh) + ':' + convert(mm);
			}
			mm += 1;
			if (mm == m) {
				hh += 1, mm = 0;
			}
			if (hh == h) {
				hh = 0;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}