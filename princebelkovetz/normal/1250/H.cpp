#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define endl "\n"
#define int long long
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
const int mxN = 1e5 + 7, inf = 1e9 + 7;
int fastpow(int a, int b) {
	if (!b) return 1ll;
	if (b % 2 == 1) return fastpow(a, b - 1) * a;
	int t = fastpow(a, b / 2);
	return t * t;
}
signed main() {
	int t; cin >> t;
	while (t --> 0) {
		int n, last = -1, zero; cin >> n;
		vector <int> bits;
		while (n) {
			bits.push_back(n % 3);
			n /= 3;
			if (bits[bits.size() - 1] == 2) last = bits.size() - 1;
		}
		bits.push_back(0);
		if (last != -1)
		for (int i = last; i < bits.size(); ++i) 
			if (!bits[i]) { 
				zero = i;
				bits[i] = 1;
				for (int j = i - 1; j >= 0; --j) bits[j] = 0;
				break;
			}
		int ans = 0;
		for (int i = 0; i < bits.size(); ++i) ans += pow(3, i) * bits[i];
		cout << ans << endl;
	}


}