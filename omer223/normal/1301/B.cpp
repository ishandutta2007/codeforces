#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <bitset>
#include <set>
#include <queue>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 1e6;
int n, a[sz];

void solve() {
	cin >> n;
	foru(i, 0, n)cin >> a[i];
	set<int> s;
	foru(i, 0, n) {
		if (a[i] == -1) {
			if (i > 0)s.insert(a[i - 1]);
			if (i < n - 1)s.insert(a[i + 1]);
		}
	}
	s.erase(-1);
	if (s.empty()) {
		cout << 0 << ' ' << 1 << '\n';
		return;
	}
	int k = (*s.begin() + *s.rbegin()) / 2;
	foru(i, 0, n) {
		if (a[i] == -1)a[i] = k;
	}
	int m = 0;
	foru(i, 0, n - 1)m = max(m, abs(a[i] - a[i + 1]));
	cout << m << ' ' << k << '\n';
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}