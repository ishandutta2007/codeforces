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
	int x;
	cin >> x;
	if (x == 1)
		return cout << 1 << ' ' << 0 << endl, 0;
	int y = 1;
	vector<int> vec;
	for (int i = 2; i * i <= x; i++) {
		if (x % i) continue;
		y *= i;
		int cnt = 0;
		while (x % i == 0)
			x /= i, cnt++;
		vec.PB(cnt);
	}
	if (x > 1)
		y *= x, vec.PB(1);
	cout << y << ' ';
	sort(all(vec));

	if (vec[0] == vec.back() and (vec[0] & (vec[0] - 1)) == 0)
		cout << __builtin_ctz(vec[0]) << endl;
	else {
		while (vec.back() & (vec.back() - 1))
			vec.back()++;
		cout << 1 +  __builtin_ctz(vec.back()) << endl;
	}
	return 0;
}