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

map<pii, int> mp;

pii frac(int x, int y) {
	int d = __gcd(abs(x), abs(y));
	x /= d;
	y /= d;
	if (y < 0)
		x = -x, y = -y;
	return MP(x, y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int a[n];
	int b[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	for (int i = 0; i < n; i++) {
		if (a[i] != 0)
			mp[frac(-b[i], a[i])]++;
		else if (b[i] == 0)
			mp[MP(0, 0)]++;
	}
	int ans = 0;
	for (auto cnt : mp)
		if (cnt.L != MP(0, 0))
			smax(ans, cnt.R);
	cout << ans + mp[MP(0, 0)] << endl;
	return 0;
}