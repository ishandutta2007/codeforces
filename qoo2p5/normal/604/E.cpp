#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned ll
#define ld long double
#define sz(x) (int) x.size()
#define INF (int) 1e9
#define LINF (ll) 1e18
#define EPS 1e-10
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eq(a, b) abs(a - b) < EPS

int n, k;
int a[100000];

int mex(int a, int b) {
	for (int i = 0; i <= 2; i++) {
		if (i != a && i != b) {
			return i;
		}
	}

	return -666;
}

int manual[5] = {0, 1, 0, 1, 2};

int f(int x) {
	if (x <= 4) {
		return manual[x];
	}

	if (x % 2 == 1) {
		return 0;
	} else {
		return mex(f(x - 1), f(x / 2));
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int ans = 0;
	if (k % 2 == 0) {
		for (int i = 0; i < n; i++) {
			if (a[i] == 1) {
				ans ^= 1;
			} else if (a[i] == 2) {
				ans ^= 2;
			} else {
				if (a[i] % 2 == 0) {
					ans ^= 1;
				}
			}
		}
	} else {
		for (int i = 0; i < n; i++) {
			ans ^= f(a[i]);
		}
	}

	if (ans) {
		cout << "Kevin\n";
	} else {
		cout << "Nicky\n";
	}

	return 0;
}