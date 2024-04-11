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
		int n; cin >> n;
		string s; cin >> s;
		bool le = false, ri = false;
		for (auto x : s) {
			if (x == '>') le = true;
			else if (x == '<') ri = true;
		}
		if (!le or !ri) cout << n;
		else {
			vector <bool> ok(n);
			int cnt = 0;
			for (int i = 0; i < n ;++i){
				if (s[i] == '-')
					ok[i] = true, ok[(i + 1) % n] = true;
			}
			for (auto x : ok)
				cnt += x;
			cout << cnt;
		}
		cout << '\n';
	}
	return 0;
}