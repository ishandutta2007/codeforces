#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n1, n2, n3;
	cin >> n1 >> n2 >> n3;

	vector<int> a1(n1), a2(n2), a3(n3);
	for (int i = 0; i < n1; i++) cin >> a1[i];
	for (int i = 0; i < n2; i++) cin >> a2[i];
	for (int i = 0; i < n3; i++) cin >> a3[i];

	int mn1 = *min_element(a1.begin(), a1.end());
	int mn2 = *min_element(a2.begin(), a2.end());
	int mn3 = *min_element(a3.begin(), a3.end());

	long long sum1 = accumulate(a1.begin(), a1.end(), 0ll);
	long long sum2 = accumulate(a2.begin(), a2.end(), 0ll);
	long long sum3 = accumulate(a3.begin(), a3.end(), 0ll);

	long long sum = sum1 + sum2 + sum3, ans = 0;

	ans = max(ans, sum - 2ll * mn1 - 2ll * mn2);
	ans = max(ans, sum - 2ll * mn2 - 2ll * mn3);
	ans = max(ans, sum - 2ll * mn3 - 2ll * mn1);

	ans = max(ans, sum - 2ll * sum1);
	ans = max(ans, sum - 2ll * sum2);
	ans = max(ans, sum - 2ll * sum3);
	cout << ans << '\n';
	return 0;
}