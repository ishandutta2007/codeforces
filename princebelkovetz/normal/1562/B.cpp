#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <queue>
#include <string>

using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double

const int mod = 1e9 + 7, N = 1e5 + 2;

bool prime(int x) {
	if (x == 1) return true;
	for (int i = 2; i * i <= x; ++i) {
		if (x % i == 0) return true;
	}
	return false;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt; cin >> tt;

	while (tt--) {
		int n; 
		string s; 
		cin >> n >> s;
		int len = 228, ans = 0;
		for (int i = 0; i < n; ++i) {
			int cur = s[i] - '0';
			if (prime(cur)) len = 1, ans = cur;
			for (int j = i + 1; j < n; ++j) {
				cur = cur * 10 + (s[j] - '0');
				if (prime(cur) and len > 2) len = 2, ans = cur;
				for (int k = j + 1; k < n; ++k) {
					cur = cur * 10 + (s[k] - '0');
					if (prime(cur) and len > 3) len = 3, ans = cur;
					cur -= (s[k] - '0');
					cur /= 10;
				}
				
				cur -= (s[j] - '0');
				cur /= 10;
			}
		}
		cout << len << '\n' << ans << '\n';
	}
	
	return 0;
}