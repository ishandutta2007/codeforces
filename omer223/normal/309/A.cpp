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
#include <iomanip>
#include <queue>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 1e6 + 5;
int n, t, len;
int a[sz];


int main() {
	fast;
	cin >> n >> len >> t;
	foru(i, 0, n)cin >> a[i];
	ll tot = 0, up;
	foru(i, 1, n) {
		int l = 1, r = i + 1, mid, lstin = i, lstout = n + 1;
		while (l <= r) {
			mid = (l + r + 1) / 2;
			up = (2 * t - (a[i] - a[mid - 1]));
			if (up >= 0 && up / len == (2 * t) / len) {
				lstin = mid - 1;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		l = 1, r = lstin;
		lstout = lstin;
		while (l <= r) {
			mid = (l + r + 1) / 2;
			up = (2 * t - (a[i] - a[mid - 1]));
			if (up >= 0 && up / len == (2 * t) / len - 1) {
				lstout = mid - 1;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		tot += (1 + (2 * t) / len)*(i - lstin);
		tot += ((2 * t) / len)*(lstin - lstout);
		l = 1, r = i, lstin = 0;//lstin is excluded
		while (l <= r) {
			mid = (l + r + 1) / 2;
			ll up = (2 * t - (len - (a[i] - a[mid - 1])));
			if (up >= 0 && up / len == (2 * t) / len) {
				lstin = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		lstout = lstin;
		l = lstout + 1, r = i;
		while (l <= r) {
			mid = (l + r + 1) / 2;
			ll up = (2 * t - (len - (a[i] - a[mid - 1])));
			if (up >= 0 && up / len == (2 * t) / len - 1) {
				lstout = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		tot += (1 + (2 * t) / len)*lstin;
		tot += ((2 * t) / len)*(lstout - lstin);
	}
	ld ret = (ld)tot / 4;
	cout << fixed << setprecision(10) << ret << '\n';
	return 0;
}