#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <bitset>
#include <numeric>
#include <unordered_map>
#include <set>
#include <unordered_set>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

ll a, b;

vector<pll> getDivisors(ll x) {
	vector<pll> ans;
	for (ll i = 1; i * i <= x; i++) {
		if (x%i == 0) {
			ans.pb({ i,x / i });
			if (i*i != x)ans.pb({ x / i,i });
		}
	}
	sort(ans.begin(), ans.end());
	return ans;
}

inline void upd(ll& ans, ll x) {
	if (ans == -1)ans = x;
	else ans = min(ans, x);
}

int main() {
	fast;
	cin >> a >> b;
	vector<pll> va = getDivisors(a), vb = getDivisors(b), vab = getDivisors(a + b);
	int asz = va.size(), bsz = vb.size(),l,r,mid,bst;
	ll ans = -1;
	for (pll dim : vab) {
		bst = -1;
		l = 1, r = asz;
		while (l <= r) {
			mid = (l + r + 1) / 2;
			if (va[mid - 1].first <= dim.first) {
				bst = mid - 1;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		if (bst != -1&&va[bst].second<=dim.second)upd(ans, 2 * (dim.first + dim.second));
		bst = -1;
		l = 1, r = bsz;
		while (l <= r) {
			mid = (l + r + 1) / 2;
			if (vb[mid - 1].first <= dim.first) {
				bst = mid - 1;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		if (bst != -1&&vb[bst].second<=dim.second)upd(ans, 2 * (dim.first + dim.second));
		bst = -1;
		l = 1, r = asz;
		while (l <= r) {
			mid = (l + r + 1) / 2;
			if (va[mid - 1].first <= dim.second) {
				bst = mid - 1;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		if (bst != -1 && va[bst].second <= dim.first)upd(ans, 2 * (dim.first + dim.second));
		bst = -1;
		l = 1, r = bsz;
		while (l <= r) {
			mid = (l + r + 1) / 2;
			if (vb[mid - 1].first <= dim.second) {
				bst = mid - 1;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		if (bst != -1 && vb[bst].second <= dim.first)upd(ans, 2 * (dim.first + dim.second));
	}
	cout << ans << endl;
	return 0;
}