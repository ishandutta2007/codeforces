#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, A[1000005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
	}
	reverse(A + 1, A + 1 + n);
	int m_dp = 0, c_dp = 0;
	multiset<int> slp_dp;
	for (int i = 1; i <= n; i++) {
		// y = 1 * x - A[i], {A[i], A[i]}
		m_dp += 1;
		c_dp += -A[i];
		slp_dp.insert(A[i]);
		slp_dp.insert(A[i]);
		
		while (m_dp > 0) {
			int x_1 = *slp_dp.rbegin();
			int m_2 = m_dp - 1;
			int c_2 = (m_dp * x_1) + c_dp - (m_dp - 1) * x_1;
			m_dp = m_2;
			c_dp = c_2;
			slp_dp.erase(--slp_dp.end());
		}
	}
	cout << c_dp << '\n';
}