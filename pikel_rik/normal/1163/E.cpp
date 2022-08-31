#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n);
	for (auto &x : a) cin >> x;

	sort(a.begin(), a.end());

	vector<int> basis(20, -1), ind_mask(20);
	vector<int> ans, gray = {0};

	for (int b = 1, l = 0; b < 20; b++) {
		vector<int> temp(gray.rbegin(), gray.rend());
		for (auto &x : temp) {
			x |= (1 << (b - 1));
		}
		gray.insert(gray.end(), temp.begin(), temp.end());

		for (; l < n && a[l] < (1 << b); l++) {
			int mask = 0;
			for (int j = 0; j < b; j++) {
				if (a[l] >> j & 1) {
					if (basis[j] != -1) {
						a[l] ^= a[basis[j]];
						mask ^= ind_mask[j];
					} else {
						basis[j] = l;
						ind_mask[j] = mask ^ (1 << j);
						break;
					}
				}
			}
		}

		if (count(basis.begin(), basis.begin() + b, -1) > 0) {
			continue;
		}

		vector<int> new_ans((1 << b) - 1);
		for (int i = 1; i < (1 << b); i++) {
			int x = gray[i] ^ gray[i - 1];
			int &res = new_ans[i - 1];
			for (int j = b - 1; j >= 0; j--) {
				if (x >> j & 1) {
					res ^= a[basis[j]];
					x ^= ind_mask[j];
				}
			}
		}
		ans.swap(new_ans);
	}

	cout << (32 - __builtin_clz(ans.size() + 1) - 1) << '\n' << 0 << ' ';
	for (int i = 0, x = 0; i < ans.size(); i++) {
		x ^= ans[i];
		cout << x << ' ';
	}
	cout << '\n';
	return 0;
}