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
	int n, m;
	cin >> n >> m;
	if (m == 0)
		return cout << 1 << endl, 0;
	if (m <= n / 2) {
		cout << m << endl;
		return 0;
	}
	if (n & 1) {
		if (m == n / 2 + 1)
			cout << n / 2 << endl;
		else
			cout << n - m << endl;
	}
	else
		cout << n - m << endl;
	return 0;
}