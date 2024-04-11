
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;


int main() {
	fast;
	int n;
	ll t;
	cin >> n >> t;
	vector<pll> v(n);
	foru(i, 0, n)cin >> v[i].first >> v[i].second;
	ll l = 1, r = n, bst = -1, mid;
	vector<ll> ans;
	while (l <= r) {
		mid = (l + r + 1) / 2;
		set<pll> s;
		foru(i, 0, n) {
			if (v[i].first >= mid) {
				s.insert(mp(v[i].second, i));
				if (s.size() > mid)s.erase(*s.rbegin());
			}
		}
		if (s.size() < mid)r = mid - 1;
		else {
			ll sum = 0;
			for (pll x : s)sum += x.first;
			if (sum > t)r = mid - 1;
			else {
				vector<ll> tmpvec;
				for (pll x : s)tmpvec.pb(x.second);
				ans = tmpvec;
				bst = mid;
				l = mid + 1;
			}
		}
	}
	if (bst == -1) {
		cout << 0 << endl << 0 << endl;
	}
	else {
		cout << bst << endl;
		cout << ans.size() << endl;
		for (ll ppp : ans)cout << ppp + 1 << " ";
		cout << endl;
	}
	return 0;
}