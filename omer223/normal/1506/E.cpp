#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 5e5;
int n;
int a[sz], pos[sz];

void solve() {
	cin >> n;
	foru(i, 0, n) {
		cin >> a[i];
		pos[--a[i]] = i;
	}
	vector<int> mx, mn;
	set<int> is;
	int prv = -1;
	foru(i, 0, n) {
		if (a[i] == prv) {
			mx.pb(*is.rbegin());
			is.erase(*is.rbegin());
		}
		else {
			foru(j, prv + 1, a[i])
				is.insert(j);
			mx.pb(a[i]);
		}
		prv = a[i];
	}
	prv = -1;
	foru(i, 0, n) {
		if (a[i] == prv) {
			mn.pb(*is.begin());
			is.erase(*is.begin());
		}
		else {
			foru(j, prv + 1, a[i])
				is.insert(j);
			mn.pb(a[i]);
		}
		prv = a[i];
	}
	foru(i, 0, n)cout << mn[i]+1 << ' ';
	cout << '\n';
	foru(i, 0, n)cout << mx[i]+1 << ' ';
	cout << '\n';
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}