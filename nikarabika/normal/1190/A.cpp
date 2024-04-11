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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	LL n, m, k;
	set<LL> s;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		LL x;
		cin >> x;
		s.insert(x);
	}
	LL pos = 0;
	LL ans = 0;
	if (sz(s) and *s.begin() > pos)
		pos += k * ((*s.begin() - pos + k - 1) / k);
	while (sz(s)) {
		ans++;
		int remcnt = 0;
		while (sz(s) and *s.begin() <= pos) {
			s.erase(s.begin());
			remcnt++;
		}
		pos += remcnt;
		if (sz(s) and *s.begin() > pos)
			pos += k * ((*s.begin() - pos + k - 1) / k);
	}
	cout << ans << endl;
	return 0;
}