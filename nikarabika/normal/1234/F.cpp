//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int maxc = 20;
char best[1 << maxc];

void inc(int mask, int val) {
	if (best[mask] >= val)
		return;
	best[mask] = val;
	for (int i = 0; i < 20; i++)
		if ((mask >> i) & 1 ^ 1)
			inc(mask | (1 << i), val);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string s;
	cin >> s;
	for (auto &c : s) c -= 'a';
	int n = sz(s);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int mask = 0;
		for (int j = i; j < n; j++) {
			int cur = s[j];
			if ((mask >> cur) & 1)
				break;
			mask |= 1 << cur;
			smax(ans, j - i + 1 + best[((1 << 20) - 1) ^ mask]);
		}
		mask = 0;
		for (int j = i; j >= 0; j--) {
			int cur = s[j];
			if ((mask >> cur) & 1)
				break;
			mask |= 1 << cur;
			inc(mask, i - j + 1);
		}
	}
	cout << ans << endl;
	return 0;
}