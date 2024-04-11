#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <set>
#include <map>
#define int long long
#define endl "\n"
#define debug(x) cout << #x << " actually equals " << x << endl
int gcd(int a, int b) {
	if (!b) return a;
	return gcd(b, a % b);
}
using namespace std;
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(3);
	int t; cin >> t;
	while (t--) {
		string s, ans = ""; cin >> s;
		bool flag = false;
		int n = s.size();
		set <char> used;
		ans += s[0]; used.insert(s[0]);
		for (int i = 1; i < n; ++i) {
			//debug(ans);
			if (used.find(s[i]) == used.end() and s[i - 1] == ans[ans.size() - 1]) {
				ans += s[i];
				used.insert(s[i]);
			}
			else if (used.find(s[i]) == used.end() and s[i - 1] == ans[0]) {
				reverse(ans.begin(), ans.end());
				ans += s[i];
				used.insert(s[i]);
			}
			else if (used.find(s[i]) == used.end()) {
				flag = true; break;
			}
			else {
				if (i > 0) {
					for (int j = 0; j < ans.size(); ++j) {
						if (ans[j] == s[i] and ans[max(j - 1, 0ll)] != s[i - 1] and ans[min(ans.size() - 1ll, j + 1ll)] != s[i - 1]) {
							flag = true; break;
						}
					}
				}
				if (flag) break;

			}
		}
		if (flag) cout << "NO\n";
		else {
			cout << "YES\n";
			for (int i = 0; i < 26; ++i) {
				if (used.find('a' + i) == used.end()) ans += (char)('a' + i);
			}
			cout << ans << endl;
		}
	}
	return 0;
}