#include <bits/stdc++.h>

using namespace std;


const int N = 1000010;

int p[N];

bool checkPrime(int u) {
	return !p[u];
}

int go(int u) {
	if (checkPrime(u)) {
		return 1e9;
	}
	int pos = 0;
	for (int i = 2; i * i <= u; i++) {
		if (u % i == 0) {
			if (checkPrime(i)) {
				pos = max(pos, i);
			}
			if (checkPrime(u / i)) {
				pos = max(pos, u / i);
			}
		}
	}
	if (pos == 0) {
		return u;
	}
	int now = u / pos;
	return (now - 1) * pos + 1;
}

int main() {
	for (int i = 2; i < N; i++) {
		if (!p[i]) {
			for (int j = i * 2; j < N; j += i) {
				p[j] = 1;
			}
		}
	}
	int x;
	cin >> x;
	int y = go(x);
	int res = 1e9;
	for (int i = y; i <= x; i++) {
		res = min(res, go(i));
	}
	cout << res << endl;
	return 0;
}