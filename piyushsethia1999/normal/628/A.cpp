#include <bits/stdc++.h>
#define pb emplace_back
#define fi first
#define se second
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }

int kk(int a) {
	int y = 1;
	while (y <= a) {
		y *= 2;
	}
	return (y / 2);
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n; cin >> n;
	int b; cin >> b;
	int p; cin >> p; p *= n;
	int to = 0;
	while (n != 1) {
		int k = kk(n);
		to += (k / 2);
		n = n - k / 2;
	}
	cout << to * (2 * b + 1) << " " << p;
}