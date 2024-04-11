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

void solve() {
	ll sm = 0;
	vector<ll> toadd;
	int n;
	cin >> n;
	vector<ll> v(n);
	vector<int> deg(n, 0);
	foru(i, 0, n) {
		cin >> v[i]; sm += v[i];
	}
	foru(i, 0, n - 1) {
		int x, y;
		cin >> x >> y;
		deg[--x]++;
		deg[--y]++;
	}
	foru(i, 0, n) {
		foru(j, 0, deg[i] - 1)toadd.pb(v[i]);
	}
	sort(toadd.rbegin(), toadd.rend());
	foru(i, 0, n - 2) {
		cout << sm << ' ';
		sm += toadd[i];
	}
	cout << sm<< '\n';
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}