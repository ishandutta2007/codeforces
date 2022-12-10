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
	string s;
	int c0 = 0,
		c1 = 0;
	cin >> s;
	for (auto c : s) {
		if (c == '0') {
			cout << 1 << ' ' << ++c0 << '\n';
			c0 &= 3;
		}
		else {
			cout << 3 << ' ' << c1 + 1 << '\n';
			c1 ^= 2;
		}
	}
	return 0;
}