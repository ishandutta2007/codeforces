#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pii pair<int, int>
#define pip pair<int, pii>
#define all(a) a.begin(), a.end()
#define sz(a) (int) a.size()
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld long double

const int inf = 1e15 + 7;


signed main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		if (n == 1) cout << 0 << endl;
		else cout << (n % 2 == 1) + 1 + (n > 3 ? 1 : 0) << endl;
	}
}