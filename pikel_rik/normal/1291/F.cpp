#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	auto taste = [&](int c) -> char {
		cout << "? " << c + 1 << endl;
		char yes;
		cin >> yes;
		return yes;
	};

	auto reset = [&](void) -> void {
		cout << "R" << endl;
	};

	if (k == 1) {
		vector<int> bad(n);
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				taste(i);
				bad[j] |= (taste(j) == 'Y');
			}
		}
		int d = n - count(bad.begin(), bad.end(), true);
		return cout << "! " << d << endl, 0;
	}

	if (k == n) {
		int d = 0;
		for (int i = 0; i < n; i++) {
			d += taste(i) == 'N';
		}
		return cout << "! " << d << endl, 0;
	}

	k /= 2;

	vector<int> bad(n);
	for (int jump = 1; jump < n / k; jump++) {
		for (int i = 0; i < jump; i++) {
			if (i + jump >= n / k) {
				break;
			}
			for (int j = i; j < n / k; j += jump) {
				for (int ii = j * k; ii < (j + 1) * k; ii++) {
					bad[ii] |= taste(ii) == 'Y';
				}
			}
			reset();
		}
	}
	int d = n - count(bad.begin(), bad.end(), true);
	cout << "! " << d << endl;
	return 0;
}