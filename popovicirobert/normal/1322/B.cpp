#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x))

using namespace std;

const int MAXVAL = (int) 1e7;

inline int get(int l1, int r1, int l2, int r2) {
	return max(0, min(r1, r2) - max(l1, l2) + 1);
}

int main() {
#ifdef HOME
	ifstream cin("C.in");
	ofstream cout("C.out");
#endif
	int i, n;
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n;
	vector<int> a(n), b(n);
	for(i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	for(int bit = 0; (1 << bit) <= 2 * MAXVAL; bit++) {
		for(i = 0; i < n; i++) {
			b[i] = (a[i] & ((1 << (bit + 1)) - 1));
		}
		sort(b.begin(), b.end());
		int cur = 0, l1 = n - 1, r1 = n - 1, l2 = n - 1, r2 = n - 1;
		for(i = 0; i < n; i++) {
			// b[i] < (1 << (bit + 1))
			// b[i] + b[l1] >= (1 << bit)
			// b[i] + b[r1] >= (1 << (bit + 1))
			// b[i] + b[l2] >= (1 << bit) + (1 << (bit + 1))
			// b[i] + b[r2] >= (1 << (bit + 2))

			while(l1 >= 0 && b[i] + b[l1] >= (1 << bit)) {
				l1--;
			}
			while(r1 >= 0 && b[i] + b[r1] >= (1 << (bit + 1))) {
				r1--;
			}
			while(l2 >= 0 && b[i] + b[l2] >= (1 << bit) + (1 << (bit + 1))) {
				l2--;
			}
			while(r2 >= 0 && b[i] + b[r2] >= (1 << (bit + 2))) {
				r2--;
			}
			cur += get(i + 1, n - 1, l1 + 1, r1);
			cur += get(i + 1, n - 1, l2 + 1, r2);
			cur %= 2;
		}
		ans += cur * (1 << bit);
	}
	cout << ans;

	return 0;
}