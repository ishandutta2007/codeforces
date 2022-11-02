#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>
#include <cmath>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 1e6;
bitset<sz> bs;

void solve() {
	int n;
	cin >> n;
	foru(i, 0, n)bs[i + 1] = 0;
	int tmp = n;
	vector<int> v;
	do {
		v.pb(tmp);
		tmp = ceil(sqrt(tmp));
		bs[tmp] = 1;
	} while (tmp != 2);
	v.pb(2);
	vector<pii> ret;
	for (int i = 1; i < n; i++) {
		if (!bs[i])ret.pb({ i,n });
	}
	for (int i = 0; i < v.size() - 1; i++) {
		for (int j = 0; j < 2; j++)ret.pb({ v[i],v[i + 1] });
	}
	cout << ret.size() << '\n';
	for (pii x : ret)cout << x.first << ' ' << x.second << '\n';
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}