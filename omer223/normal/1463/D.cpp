#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> pt;

const int sz = 5e5;
bitset<sz> bs;

void solve() {
	int n;
	cin >> n;
	foru(i, 0, 2*n)bs[i] = 0;
	int mx = 0, mn = 0, cur = 0;
	foru(i, 0, n) {
		int tmp;
		cin >> tmp;
		bs[--tmp] = 1;
	}
	foru(i, 0, 2 * n) {
		if (bs[i]) {
			cur++; mx = max(mx, cur);
		}
		else {
			cur--; mn = min(mn, cur);
		}
	}
	cout << (n + mn - mx + 1) << '\n';
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}