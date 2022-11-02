#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>
#include <map>
#include <set>
#include <queue>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;

int ask(int l, int r) {
	cout << "? "<<l << ' ' << r << endl;
	fflush(stdout);
	int ret;
	cin >> ret;
	return ret;
}


int main() {
	fast;
	cin >> n;
	bool isl = 0;
	int ret = ask(1, n);
	if (ret != 1 && ret != n) isl = (ask(1, ret) == ret);
	else if (ret == n)isl = 1;
	int l, r, mid, bst = -1;
	if (isl) {
		l = 1, r = ret - 1;
		while (l <= r) {
			mid = (l + r + 1) / 2;
			if (ask(mid, ret) == ret) {
				bst = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
	}
	else {
		l = ret+1, r =n;
		while (l <= r) {
			mid = (l + r + 1) / 2;
			if (ask(ret, mid) == ret) {
				bst = mid;
				r = mid - 1;
			}
			else l=mid+1;
		}
	}
	cout << "! " << bst << '\n';
	return 0;
}