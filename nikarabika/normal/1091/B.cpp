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

const int maxn = 1e3 + 10;
map<pair<int, int>, int> mp;
int a[maxn],
	b[maxn],
	x[maxn],
	y[maxn],
	n;

bool is_good(int p0) {
	mp.clear();
	int xpos = a[0] + x[p0],
	ypos = b[0] + y[p0];
	for (int i = 0; i < n; i++)
		if (i != p0)
			mp[MP(x[i], y[i])] = 1;
	for (int i = 1; i < n; i++)
		if (mp[MP(xpos - a[i], ypos - b[i])]-- < 1)
			return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> x[i] >> y[i];
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i];
	for (int i = 0; i < n; i++) {
		if (is_good(i)) {
			cout << a[0] + x[i] << ' ' << b[0] + y[i] << '\n';
			return 0;
		}
	}
	return 0;
}