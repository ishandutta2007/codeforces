#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <iomanip>
#include <queue>
#include <set>
#include <map>

using namespace std;
#define int long long
#define debug(x) cout << #x << " is " << x < '\n';
#define ld long double
const int mod = 1e9 + 7, N = 1e5 + 2;

signed main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	int tt; cin >> tt;
	while (tt--) {
		string s; cin >> s;
		map <char, int> cnt;
		for (auto& x : s) cnt[x]++;
		int n = s.size();
		int ans = n;
		for (int i = 0; i < n; ++i) {
			if (cnt[s[i]] == 1) {
				ans = i;
				break;
			}
			cnt[s[i]]--;
		}
		for (int i = ans; i < n; ++i) cout << s[i];
		cout << '\n';
	}
	
}