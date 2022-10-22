#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <queue>
#include <iterator>
#include <sstream>
#include <cassert>
#define int long long
#define ull unsigned long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(7);
	int tt; cin >> tt;
	while (tt--) {
		int n, k; cin >> n >> k;
		string s; cin >> s;
		bool c = true;
		int cnt1 = 0, cnt0 = 0;
		for (int i = 0; i < k; ++i) {
			set <int> ok;
			for (int j = i; j < n; j += k) {
				if (s[j] != '?')
					ok.insert(s[j]);
			}
			if (ok.size() > 1)
				c = false;
			if (ok.size() == 0) continue;
			char x = *ok.begin(); 
			if (x == '1') cnt1++;
			if (x == '0') cnt0++;
			for (int j = i; j < n; j += k) 
				s[j] = x;
		}
		cout << (c && cnt1 <= k / 2 && cnt0 <= k / 2 ? "YES" : "NO") << '\n';
	}
	return 0;
}