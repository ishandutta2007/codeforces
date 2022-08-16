#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	auto or_query = [&](int i, int j) -> int {
		cout << "or " << i + 1 << ' ' << j + 1 << endl;
		int result;
		cin >> result;
		return result;
	};

	auto and_query = [&](int i, int j) -> int {
		cout << "and " << i + 1 << ' ' << j + 1 << endl;
		int result;
		cin >> result;
		return result;
	};

	long long sum01 = or_query(0, 1) + and_query(0, 1);
	long long sum02 = or_query(0, 2) + and_query(0, 2);
	long long sum12 = or_query(1, 2) + and_query(1, 2);

	long long all_sum = (sum01 + sum02 + sum12) / 2;

	vector<long long> a(n);
	a[0] = all_sum - sum12;
	a[1] = all_sum - sum02;
	a[2] = all_sum - sum01;

	for (int i = 3; i < n; i++) {
		a[i] = or_query(0, i) + and_query(0, i) - a[0];
	}

	sort(a.begin(), a.end());
	cout << "finish " << a[k - 1] << endl;
	return 0;
}