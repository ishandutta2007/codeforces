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

const int sz = 4e5;
int n;
int a[sz];

vector<int> lst[sz];
void reset() {
	foru(i, 0, n)lst[i+1].clear();
}

void solve() {
	cin >> n;
	reset();
	foru(i, 0, n) {
		cin >> a[i];
		lst[a[i]].pb(i);
	}
	int crmn = 5e5;
	vector<pii> bsts;//num,fromK
	foru(i, 0, n) {
		int mysz = lst[i + 1].size(), mx = 0;
		if (!mysz)continue;
		mx = max(lst[i + 1][0] + 1, n - lst[i + 1].back());
		for (int j = 0; j < mysz; j++) {
			if (!j)mx = max(mx, lst[i + 1][j]);
			else mx = max(mx, lst[i + 1][j] - lst[i + 1][j - 1]);
		}
		if (crmn > mx) {
			bsts.pb({ i + 1,mx });
			crmn = mx;
		}
	}
	if (bsts.empty()) {
		foru(i, 0, n)cout << -1 << " ";
		cout << endl;
	}
	else {
		int bstsSize = bsts.size();
		foru(i, 0, bsts.back().second - 1)cout << -1 << " ";
		ford(i, bstsSize - 1, 1) {
			foru(j, 0, bsts[i - 1].second - bsts[i].second)cout << bsts[i].first << " ";
		}
		foru(i, 0, n - bsts[0].second + 1)cout << bsts[0].first << " ";
		cout << endl;
	}
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}