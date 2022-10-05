#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 2e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

const int N = 1e6 + 5;

int sieve[N];

void prep() {
	for (int i = 0; i < N; i++) sieve[i] = 1;
	sieve[1] = 0;
	for (int i = 2; i * i <= N; i++) {
		if (sieve[i]) {
			for (int j = i * i; j <= N; j += i)
				sieve[j] = 0;
		}
	}
	for (int i = 2; i < N; i++) {
		sieve[i] += sieve[i - 1];
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	prep();
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int s = sqrt(n);
		cout << sieve[n] - sieve[s] + 1 << '\n';
	}
}