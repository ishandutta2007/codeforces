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
#define ld double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
const int mod = 1e9 + 7;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(7);
	int tt; cin >> tt;
	while (tt --> 0) {
		int p, q; 
		cin >> p >> q;
		if (p % q) cout << p;
		else {
			vector <int> d;
			int copyq = q;
			for (int i = 2; i * i <= q; ++i) {
				if (q % i == 0) d.push_back(i);
				while (q % i == 0) 
					q /= i;
			}
			if (q != 1)
				d.push_back(q);
			q = copyq;
			int ans = 0;
			for (auto x : d) {
				int copyp = p;
				while (p % q == 0) p /= x;
				ans = max(ans, p);
				p = copyp;
			}
			cout << ans;
		}
		cout << '\n';
	}

	return 0;
}