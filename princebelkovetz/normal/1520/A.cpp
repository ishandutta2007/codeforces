#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <cassert>
#include <queue>
using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define int long long

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int tt; cin >> tt;
	while (tt--) {
		int n; cin >> n;
		string s; cin >> s;
		set <char> was;
		bool ok = true;
		for (int i = 0; i < n; ++i) {
			if (was.find(s[i]) != was.end())
				ok = false;
			int j = i;
			while (j < n and s[j] == s[i])
				j++;
			was.insert(s[i]);
			i = j - 1;
		}
		cout << (ok ? "YES" : "NO") << '\n';
	}
	return 0;
}