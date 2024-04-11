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

const int sz = 5e5;
int v[sz], a[sz], n;

int main() {
	fast;
	cin >> n;
	foru(i, 0, n)cin >> a[i];
	int ret = 0, msk = 1, msb = 1;
	foru(bit, 0, 25) {
		ll cnt = 0;
		foru(i, 0, n)v[i] = (a[i] & msk);
		sort(v, v + n);
		foru(i, 0, n) {
			int lw = max(0, msb - v[i]), hgh = msk - v[i];
			cnt += upper_bound(v + i + 1, v + n, hgh) - lower_bound(v + i + 1, v + n, lw);
			cnt += v + n - lower_bound(v + i + 1, v + n, msb + (msb << 1) - v[i]);
		}
		if (cnt & 1)ret |= msb;
		msb <<= 1;
		msk |= msb;
	}
	cout << ret << '\n';
	return 0;
}