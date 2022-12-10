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
	LL n, k;
	cin >> n >> k;
	if (k * (k - 1) < n)
		return cout << "NO" << endl, 0;
	cout << "YES" << endl;
	for (int i = 0; i < n; i++) {
		int x = i % k;
		int y = (x + i / k + 1) % k;
		cout << x + 1 << ' ' << y + 1 << '\n';
	}
	return 0;
}