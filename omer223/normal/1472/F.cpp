#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>
#include <queue>


using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void solve() {
	int n, m;
	cin >> n >> m;
	vector<pii> all;
	foru(i, 0, m) {
		int r, c;
		cin >> r >> c;
		all.pb({ --c,--r });
	}
	sort(all.begin(), all.end());
	int cur = 0, fb = -1, cbad = -1;
	bool flag = 0;
	foru(i, 0, m) {
		if (i != m - 1 && all[i].ff == all[i + 1].ff) {
			if (fb != -1) {
				flag = 1;
				break;
			}
			cur = all[i++].ff;
		}
		else if (fb == -1) {
			fb = all[i].ss;
			cbad = all[i].ff;
		}
		else {
			if (all[i].ss == fb) {
				if (all[i].ff % 2 == cbad % 2) {
					flag = 1;
					break;
				}
				else {
					fb = -1;
					cbad = -1;
					cur = all[i].ff;
				}
			}
			else {
				if (all[i].ff % 2 != cbad % 2) {
					flag = 1;
					break;
				}
				else {
					fb = -1;
					cbad = -1;
					cur = all[i].ff;
				}
			}
		}
	}
	if (flag || fb != -1)cout << "NO\n";
	else cout << "YES\n";
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}