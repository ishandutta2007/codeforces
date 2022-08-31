#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	auto choose2 = [](long long x) -> long long {
		return (x * x - x) / 2;
	};

	auto find_choose2 = [&](long long x) -> long long {
		long long lo = 1, hi = (long long) 1e9;
		while (lo < hi) {
			long long mid = lo + (hi - lo + 1) / 2;
			if (choose2(mid) <= x) {
				lo = mid;
			} else {
				hi = mid - 1;
			}
		}
		return lo;
	};

	while (t--) {
		int n;
		cin >> n;

		auto query = [](int l, int r) -> long long {
			cout << "? " << l << ' ' << r << endl;
			long long x;
			return cin >> x, x;
		};

		long long total_inversions = query(1, n);

		int lo = 1, hi = n;

		int i = -1, j = -1;
		while (lo < hi && j == -1) {
			int mid = lo + (hi - lo + 1) / 2;
			auto current_inversions = query(1, mid);

			if (current_inversions == 0) {
				lo = mid;
				continue;
			}

			if (current_inversions == total_inversions) {
				hi = mid - 1;
				continue;
			}

			auto x = find_choose2(current_inversions);
			if (choose2(x) == current_inversions) {
				if (i != -1 && mid - i + 1 == x) {
					lo = mid + 1;
				} else {
					auto diff = current_inversions - query(1, mid - 1);
					if (diff == x - 1) {
						i = mid - x + 1;
						lo = mid + 1;
					} else {
						j = mid - diff;
					}
				}
			} else {
				hi = mid - 1;
			}
		}

		if (j == -1) {
			j = lo;
		}

		long long before_inversions = query(1, j - 1), after_inversions = query(j, n);
		cout << "! ";
		cout << j - find_choose2(before_inversions) << ' ';
		cout << j << ' ';
		cout << j + find_choose2(after_inversions) - 1 << endl;
	}
	return 0;
}