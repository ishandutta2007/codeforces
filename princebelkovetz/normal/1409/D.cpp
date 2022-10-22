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
#define ull unsigned long long
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(7);
	int tt; cin >> tt;
	while (tt--) {
		int n, s, copy; cin >> n >> s;
		copy = n;
		vector <int> digits;
		int sum = 0;
		while (n) {
			digits.push_back(n % 10);
			n /= 10;
			sum += digits.back();
		}
		digits.push_back(0);
		int last = 0;
		while (sum > s) {
			if (!digits[last]) {
				++last; continue;
			}
			sum -= digits[last];
			sum++;
			digits[last] = 0;
			digits[++last]++;
			int cur = last;
			while (digits[cur] == 10)
				sum -= 9, digits[cur] = 0, digits[++cur]++;
		}
		bool c = true;
		int res = 0;
		for (int i = 0, pw = 1; i < digits.size(); ++i, pw *= 10) {
			res += digits[i] * pw;
		}
		cout << res - copy << '\n';

	}
	
}