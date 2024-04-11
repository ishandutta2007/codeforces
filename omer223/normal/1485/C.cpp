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
	ll x, y;
	cin >> x >> y;
	ll cnt = 0, b;
	for (b = 1; b <= y && b - 1 <= (x / (b + 1)); b++)cnt += (b - 1);
	if (b <= y) {
		ll cur = x / (b + 1);
		while (cur) {
			ll l = b, r = y, mid, bst = b - 1;
			while (l <= r) {
				mid = (l + r + 1) / 2;
				if (x / (mid + 1) == cur) {
					bst = mid;
					l = mid + 1;
				}
				else r = mid - 1;
			}
			cnt += (cur * (bst - b + 1));
			b = bst + 1;
			cur--;
		}
	}
	cout << cnt << '\n';
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}