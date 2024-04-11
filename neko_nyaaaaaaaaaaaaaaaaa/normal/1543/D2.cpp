#include <bits/stdc++.h>
using namespace std;
 
#define int long long

int n, k, ds;

void count_digit(int x) {
	ds = 0;
	while (x > 0) {
		ds++; x /= k;
	}
}

int add(int x, int y) {
	int res = 0, pw = 1;
	for (int i = 0; i < ds; i++) {
		int dx = x % k; x /= k;
		int dy = y % k; y /= k;

		res += pw*((dx + dy) % k);
		pw *= k;
	}
	return res;
}

int sub(int x, int y) {
	int res = 0, pw = 1;
	for (int i = 0; i < ds; i++) {
		int dx = x % k; x /= k;
		int dy = y % k; y /= k;

		res += pw*((dx - dy + k) % k);
		pw *= k;
	}
	return res;
}

void solve() {
	cin >> n >> k;
	count_digit(n);

	// password -= guessed
	// to restore password, += sum of all guesses so far
	for (int i = 0; i < n; i++) {
		int guess;
		if (i % 2) {
			guess = sub(0, i);
			guess = add(guess, i-1);
		} else {
			guess = i;
			if (i > 0) guess = sub(guess, i-1);
		}
		cout << guess << endl;
		int rs; cin >> rs;
		if (rs == 0) {
			continue;
		} else {
			return;
		}
	}
}
 
signed main() {
	//ios::sync_with_stdio(0); cin.tie(0);
 
	int t; cin >> t;
	while (t--) {
		solve(); 
	}
 
	return 0;
}