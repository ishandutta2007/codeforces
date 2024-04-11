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
#include <set>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 5e5;
int n;
ll a[sz];

inline int calcMSB(int num, int upper) { //num<<(upper-1) is on
	for (int i = upper - 2; i >= 0; i--) {
		if ((num >> i) & 1)return i + 1;
	}
	return 0;
}

int foo(int i, int j, int msb) {
	if (j - i <= 1)return 0;
	vector<pair<pii, int>> v;
	vector<int> costs, szs;
	int prv = calcMSB(a[i], msb) , prvStart = i;
	for (int l = i + 1; l <= j; l++) {
		int xx = calcMSB(a[l], msb);
		if (xx != prv) {
			v.pb({ { prvStart,l - 1 }, prv });
			szs.pb(l - prvStart);
			prv = xx;
			prvStart = l;
		}
	}
	v.pb({ {prvStart,j},prv });
	szs.pb(j - prvStart + 1);
	int vsz = v.size();
	for (int i = 0; i < vsz; i++)costs.pb(foo(v[i].first.first, v[i].first.second, v[i].second));
	ll bst = n;
	for (int i = 0; i < vsz; i++) {
		ll bef = 0, aft = 0;
		for (int j = 0; j < i; j++)bef += szs[j];
		for (int j = i + 1; j < vsz; j++)aft += (szs[j] - 1);
		bst = min(bst, (i ? bef - 1 : 0) + aft + costs[i]);
	}
	return bst;
}

int main() {
	fast;
	cin >> n;
	ll tmp;
	foru(i, 0, n) {
		cin >> a[i];
	}
	sort(a, a + n);
	cout << min(n - 2, foo(0, n - 1, 31)) << '\n';
	return 0;
}