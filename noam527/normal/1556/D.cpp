#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

int n, k;

int askand(int i, int j) {
	cout << "and " << i + 1 << " " << j + 1 << '\n';
	cout.flush();
	int res;
	cin >> res;
	return res;
}

int askor(int i, int j) {
	cout << "or " << i + 1 << " " << j + 1 << '\n';
	cout.flush();
	int res;
	cin >> res;
	return res;
}

void answer(int ans) {
	cout << "finish " << ans << '\n';
	cout.flush();
}

void solve() {
	cin >> n >> k;
	vector<int> p(n - 1), q(n - 1), x(n - 1);
	for (int i = 0; i < n - 1; i++) {
		p[i] = askand(i, i + 1);
		q[i] = askor(i, i + 1);
		x[i] = p[i] ^ q[i];
	}
	int a = askand(0, 2), ba = askor(0, 2), c = a ^ ba;
	vector<int> arr(n, 0);
	for (int b = 0; b < 30; b++) {
		int B = 1 << b;
		int lst = 0;
		for (int i = 1; i < n; i++) {
			if (x[i - 1] & B)
				lst ^= 1;
			if (lst)
				arr[i] |= B;
		}
		int flip = 0;
		int found = 0;
		for (int i = 0; i < n - 1; i++) {
			if (p[i] & B) {
				if ((arr[i] & B) == 0) flip = 1;
				found = 1;
				break;
			}
			if ((q[i] & B) == 0) {
				if (arr[i] & B) flip = 1;
				found = 1;
				break;
			}
		}
		if (!found) {
			if (ba & B)
				flip = 1;
		}

		if (flip) {
			for (int i = 0; i < n; i++)
				arr[i] ^= B;
		}
	}

	sort(arr.begin(), arr.end());
	answer(arr[k - 1]);
}

int main() {
	//ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	//cin >> tst;
	while (tst--) solve();
}