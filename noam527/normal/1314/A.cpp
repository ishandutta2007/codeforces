#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 2e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n;
vector<pair<ll, ll>> a;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	a.resize(n);
	for (auto &i : a) cin >> i.first;
	for (auto &i : a) cin >> i.second;
	sort(a.begin(), a.end());
	ll ans = 0;
	
	int nxta = 0;
	ll x = -1, ssum = 0;
	multiset<ll> S;
	while (nxta < n || S.size() > 0) {
		while (nxta < n && a[nxta].first == x) {
			ssum += a[nxta].second;
			S.insert(a[nxta].second);
			nxta++;
		}
		if (S.size() > 0) {
			ssum -= *S.rbegin();
			S.erase(prev(S.end()));
			ans += ssum;
			x++;
		}
		else {
			x = a[nxta].first;
		}
	}
	cout << ans << '\n';
}