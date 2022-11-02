#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <unordered_map>
#include <unordered_set>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


const int sz = 1e6 + 5;
int n;
int a[sz];

void solve() {
	cin >> n;
	foru(i, 0,2* n)cin >> a[i];
	sort(a, a + 2 * n);
	vector<pii> inst;
	multiset<int, greater<int>> rem;
	ford(iter, 2 * n - 2, 0) {
		rem.clear();
		inst.clear();
		foru(i, 0, 2 * n - 1) {
			if (i == iter)continue;
			rem.insert(a[i]);
		}
		ll tx = a[2 * n - 1] + a[iter], crx = a[2*n-1];
		inst.pb({ a[2 * n - 1],a[iter] });
		bool bad = 0;
		while (!rem.empty()) {
			ll cand = *rem.begin(); rem.erase(rem.find(cand));
			if (rem.find(crx - cand) != rem.end()) {
				inst.pb({ cand,crx - cand });
				rem.erase(rem.find(crx - cand));
				crx = cand;
			}
			else {
				bad = 1;
				break;
			}
		}
		if (!bad) {
			cout << "YES\n" << tx << '\n';
			for (pii ppp : inst)cout << ppp.ff << ' ' << ppp.ss << '\n';
			return;
		}
	}
	cout << "NO\n";
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}