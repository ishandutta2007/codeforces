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

char ch[] = "RGB";

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string s;
	cin >> s >> s;
	int ans = 1e9,
		ansi, ansj, ansk;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) if (i ^ j) {
			int k = i ^ j ^ 3;
			int cur = 0;
			for (int pos = 0; pos < sz(s); pos += 3)
				cur += s[pos] != ch[i];
			for (int pos = 1; pos < sz(s); pos += 3)
				cur += s[pos] != ch[j];
			for (int pos = 2; pos < sz(s); pos += 3)
				cur += s[pos] != ch[k];
			if (cur < ans) {
				ans = cur;
				ansi = i;
				ansj = j;
				ansk = k;
			}
		}
	cout << ans << '\n';
	for (int pos = 0; pos < sz(s); pos += 3)
		s[pos] = ch[ansi];
	for (int pos = 1; pos < sz(s); pos += 3)
		s[pos] = ch[ansj];
	for (int pos = 2; pos < sz(s); pos += 3)
		s[pos] = ch[ansk];
	cout << s << endl;
	return 0;
}