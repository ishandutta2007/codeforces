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

const int sz = 2e4;
int n;
ll a[sz];

void solve() {
	cin >> n;
	ll sm = 0;
	foru(i, 0, n) {
		cin >> a[i]; sm += a[i];
	}
	if (sm%n) {
		cout << -1 << endl;
		return;
	}
	ll target = sm / n;
	vector<pair<pll, ll>> inst;
	for (ll i = 1; i < n; i++) {
		if (a[i] % (i + 1) == 0) {
			inst.pb({ {i + 1,1}, a[i] / (i + 1) });
			a[0] += a[i];
			a[i] = 0;
		}
		else {
			ll x = a[i] / (i + 1), left = (i + 1) - a[i] % (i + 1);
			inst.pb({ {1,i + 1}, left });
			a[0] -= left;
			a[i] += left;
			i--;
		}
	}
	for (ll i = 1; i < n; i++) {
		inst.pb({ { 1,i + 1 }, target });
	}
	cout << inst.size() << endl;
	for (auto x : inst) {
		cout << x.first.first << " " << x.first.second << " " << x.second << endl;
	}
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}