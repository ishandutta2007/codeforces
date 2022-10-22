#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <iterator>
#include <sstream>
#define endl "\n"
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
const int inf = 1e10;
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(3);
	int t; cin >> t;
	while (t --> 0) {
		int n, k; cin >> n >> k;
		vector <int> a(n);
		for (auto& x : a)cin >> x;
		sort(a.rbegin(), a.rend());
		int ppl = 0, ans = 0, curn;
		for (int i = 0; i < n; ++i) {
			curn = a[i];
			++ppl;
			if (curn * ppl >= k) {
				++ans;
				ppl = 0;
			}
		}
		cout << ans << endl;
	}
}