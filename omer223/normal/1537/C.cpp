
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (ll i = k; i < n; i++)
#define ford(i, k, n) for (ll i = k; i >= n; i--)
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <bitset>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;



int main() {
	fast;
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<ll> a(n);
		foru(i, 0, n)cin >> a[i];
		sort(a.begin(), a.end());
		ll bst = 1e18;
		foru(i, 0, n - 1)bst = min(bst, a[i + 1] - a[i]);
		vector<ll> ans(n);
		int idx = -1;
		foru(i, 0, n - 1) {
			if (a[i + 1] - a[i] == bst) {
				idx = i;
				break;
			}
		}
		int ctr = 1;
		ans[0] = a[idx];
		ans[n - 1] = a[idx + 1];
		foru(i, 1, n - 1) {
			ans[i] = a[(idx + i + 1) % n];
		}
		foru(i, 0, n)cout << ans[i] << ' ';
		cout << '\n';
	}
	return 0;
}