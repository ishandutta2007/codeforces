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
	if (n & 1 ^ 1)
		return cout << "NO\n", 0;
	cout << "YES\n";
	for (int i = 0; i + 2 < n; i+=2) {
		cout << 2 * i + 1 << ' ' << 2 * i + 4 << ' ';
	}
	cout << 2 * n - 1 << ' ';
	for (int i = 0; i + 2 < n; i+=2) {
		cout << 2 * i + 2 << ' ' << 2 * i + 3 << ' ';
	}
	cout << 2 * n << endl;
	return 0;
}