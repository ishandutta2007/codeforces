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
int bpow(int a, int b) {
	if (!b) return 1;
	if (b & 1) return (a * bpow(a, b - 1)) % mod;
	int t = bpow(a, b / 2);
	return (t * t) % mod;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(7);
	int tt; cin >> tt;
	while (tt--) {
		int n; cin >> n;
		string s; cin >> s;
		int cnt1 = 0, cnt2 = 0;
		for (int i = 0; i < n - 1; ++i) {
			if (s[i] == '0' and s[i + 1] == '1') 
				cnt1++;
			else if (s[i] == '1' and s[i + 1] == '0') 
				cnt2++;
		}
		cout << (n - max(cnt1, cnt2) * 2) / 2 << '\n';
	}
	return 0;
}