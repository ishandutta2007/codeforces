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
#include <locale>
#define int long long
#define ull unsigned long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(7);
	int tt; cin >> tt;
	while (tt--) {
		string s, t = ""; cin >> s;
		int n = s.size();
		vector <int> ok;
		for (int i = 0; i < n; ++i) {
			if (s[i] == 'B' and !ok.empty() and s[ok.back()] == 'A') {
				ok.pop_back();
			}
			else {
				ok.push_back(i);
			}
		}
		if (ok.empty()) {
			cout << "0\n";
			continue;
		}
		int no = 0;
		for (int i = 0; i < ok.size() - 1; ++i) {
			if (s[ok[i]] == 'B' and s[ok[i + 1]] == 'B') {
				no += 2;
				++i;
			}
		}
		cout << ok.size() - no << '\n';
	}
	return 0;
}