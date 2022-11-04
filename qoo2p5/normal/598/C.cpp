#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned ll
#define ld long double
#define sz(x) (int) x.size()
#define INF (int) 1e9
#define LINF (ll) 1e18
#define EPS 1e-10
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eq(a, b) abs(a - b) < EPS
#define M_PI 3.141592653589

int n;
vector<pair<ld, int>> v;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		ld x, y;
		cin >> x >> y;
		v.pb(mp(atan2(y, x), i + 1));
	}

	sort(v.begin(), v.end());

	ld best_r = INF;
	int a = 0;
	int b = 0;

	for (int i = 0; i < n; i++) {
		ld r = v[(i + 1) % n].first - v[i].first;
		if (r < 0) {
			r += 2 * M_PI;
		}
		if (r < best_r) {
			best_r = r;
			a = v[i].second;
			b = v[(i + 1) % n].second;
		}
	}

	cout << a << " " << b << endl;

    return 0;
}