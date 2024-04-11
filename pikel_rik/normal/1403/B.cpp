#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1000 * 1000 + 5;

int n, a[N], b[N], sorted_a[N];

struct BIT {
	long long bit[N + 1];

	void add(int i, int x) {
		while (i <= N) {
			bit[i] += x;
			i += i & -i;
		}
	}

	long long query(int i) {
		long long sum = 0;
		while (i > 0) {
			sum += bit[i];
			i -= i & -i;
		}
		return sum;
	}
} bit1, bit2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	copy(a, a + n, sorted_a);

	sort(sorted_a, sorted_a + n);

	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		mp[sorted_a[i]] = i + 1;
	}

	for (int i = 0; i < n; i++) {
		b[i] = mp[a[i]];
	}

	long long triplets = 0;

	for (int k = 0; k < n; k++) {
		triplets += bit2.query(N) - bit2.query(b[k]);
		long long cur_inv = bit1.query(N) - bit1.query(b[k]);
		bit2.add(b[k], cur_inv);
		bit1.add(b[k], 1);
	}

	cout << triplets << '\n';
	return 0;
}