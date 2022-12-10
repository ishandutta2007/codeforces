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

const int maxn = 2e5 + 10;
int last[maxn],
	first[maxn];
string s, t;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> s >> t;
	int tpos = 0;
	memset(first, 63, sizeof first);
	first[0] = -1;
	for (int i = 0; i < sz(s); i++) {
		if (tpos < sz(t) and s[i] == t[tpos])
			tpos++;
		smin(first[tpos], i);
	}
	tpos = 0;
	memset(last, -1, sizeof last);
	last[0] = sz(s);
	for (int i = sz(s) - 1; i >= 0; i--) {
		if (tpos < sz(t) and s[i] == t[sz(t) - tpos - 1])
			tpos++;
		smax(last[tpos], i);
	}
	int ans = 0;
	for (int i = 0; i <= sz(t); i++) {
		smax(ans, last[sz(t) - i] - first[i] - 1);
	}
	cout << ans << endl;
	return 0;
}