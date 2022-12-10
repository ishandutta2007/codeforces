//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	if (n & 1 ^ 1) {
		for (int i = 0; i < n * n; i++) {
			if (i & 1)
				cout << i / 2 + 1 << ' ';
			else
				cout << (n * n) - i / 2 << ' ';
			if (i % n == n - 1)
				cout << '\n';
		}
		return 0;
	}
	int k = n / 2;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= k; j++)
			cout << i * k + j << ' ';
		cout << n * k + i + 1 << ' ';
		for (int j = 1; j <= k; j++)
			cout << n * n - (k * (i + 1)) + j << ' ';
		cout << '\n';
	}
	return 0;
}