#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 100;
int a[sz][sz];
int n, m;

void solve() {
	cin >> n >> m;
	foru(i, 0, n) {
		foru(j, 0, m)cin >> a[i][j];
	}
	ll tot = 0;
	foru(i, 0, (n + 1) / 2) {
		foru(j, 0, (m + 1) / 2) {
			vector<int> v;
			v.pb(a[i][j]);
			if (i != n - i - 1) v.pb(a[n - i - 1][j]);
			if (j != m - j - 1) v.pb(a[i][m - j - 1]);
			if (i != n - i - 1 && j != m - j - 1) v.pb(a[n - i - 1][m - j - 1]);
			sort(v.begin(), v.end());
			int vsz = v.size();
			foru(i, 0, vsz)tot += abs(v[vsz / 2] - v[i]);
		}
	}
	cout << tot << endl;
}


int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}