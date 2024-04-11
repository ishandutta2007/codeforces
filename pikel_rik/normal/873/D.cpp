#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

const int N = 1e5 + 5;

int n, c, k, a[N], cur = 1;

void mergesort(int l, int r, int k) {
	c++;
	if (l + 1 == r && k) {
		cout << "-1\n";
		exit(0);
	}
	if (k == 0) {
		for (int i = l; i < r; i++) {
			a[i] = cur++;
		}
		return;
	}
	k -= 2;
	int mid = (l + r) >> 1;
	if ((k / 2) % 2 == 0) {
		mergesort(mid, r, k - k / 2);
		mergesort(l, mid, k / 2);
	} else {
		if (mid - l > r - mid) {
			mergesort(mid, r, k - k / 2 - 1);
			mergesort(l, mid, k / 2 + 1);
		} else {
			mergesort(mid, r, k - k / 2 + 1);
			mergesort(l, mid, k / 2 - 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;

	if (k % 2 == 0) {
		cout << "-1\n";
		return 0;
	}

	mergesort(0, n, k - 1);
	for (int i = 0; i < n; i++) cout << a[i] << ' '; cout << '\n';
	return 0;
}