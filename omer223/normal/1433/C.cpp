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
#include <queue>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


int main() {
	fast;
	int t;
	cin >> t;
	while (t--) {
		int n, mx = 0;
		cin >> n;
		vector<int> v(n);
		foru(i, 0, n) {
			cin >> v[i];
			mx = max(v[i], mx);
		}
		int ret = -1;
		foru(i, 0, n) {
			if (v[i] == mx) {
				if ((i&&v[i - 1] != mx) || (i != n - 1 && v[i + 1] != mx)) {
					ret = i + 1;
					break;
				}
			}
		}
		cout << ret << '\n';
	}
	return 0;
}