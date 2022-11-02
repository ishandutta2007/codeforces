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
#include <bitset>
#include <stack>
#include <set>
#include <queue>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 1e6 + 5;
ll a[sz], n;


int main() {
	fast;
	ll k;
	cin >> n >> k;
	ll mx = -1e15, mn = 1e15, tmp;
	foru(i, 0, n) {
		cin >> tmp;
		a[i] = tmp;
		mx = max(mx, tmp);
		mn = min(mn, tmp);
	}
	if (k == 1)cout << mn << endl;
	else if (k == 2) {
		vector<int> mns(n), mxs(n);
		foru(i, 0, n) {
			if (!i) {
				mns[i] = a[i]; mxs[n-i-1] = a[n-i-1];
			}
			else {
				mns[i] = min(mns[i - 1], (int)a[i]); mxs[n-i-1] = min(mxs[n-i], (int)a[n-i-1]);
			}
		}
		int bst = -1e9;
		foru(i, 0, n - 1)bst = max(bst, max(mns[i], mxs[i + 1]));
		cout << bst << endl;

	}
	else cout << mx << endl;
	return 0;
}