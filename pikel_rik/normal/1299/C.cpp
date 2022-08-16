#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n);
	for (auto &x : a) cin >> x;

	vector<pair<int, long long>> st;
	for (int i = 0; i < n; i++) {
		st.emplace_back(1, a[i]);
		while (st.size() > 1) {
			auto &[l1, sum1] = st[st.size() - 2];
			auto &[l2, sum2] = st[st.size() - 1];
			if (sum1 * l2 > sum2 * l1) {
				sum1 += sum2;
				l1 += l2;
				st.pop_back();
			} else {
				break;
			}
		}
	}

	cout << fixed << setprecision(12);
	for (auto &[l, sum] : st) {
		double value = (double)sum / l;
		for (int i = 0; i < l; i++) {
			cout << value << '\n';
		}
	}
	return 0;
}