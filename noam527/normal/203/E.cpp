#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
const int md = 1e9 + 7;
const long long hs = 137;
//const double pi = acos(-1);
typedef long long ll;
typedef long double ldb;
using namespace std;

struct rob {
	int c, f;
	rob(int c = 0, int f = 0) : c(c), f(f) {};
	bool operator < (rob &a) {
		return f < a.f;
	}
};

int n, d, s;
ll tot = 1;
bool can = false;
vector<rob> a, b;

int main() {
	fast;
	cin >> n >> d >> s;
	for (int i = 0, c, f, l; i < n; i++) {
		cin >> c >> f >> l;
		tot += (c - 1);
		if (l >= d) {
			a.push_back(rob(c, f));
			if (c > 0) can = true;
		}
		else b.push_back(rob(c, f));
	}
	sort(a.begin(), a.end());
	if (!can) {
		ll tf = 0, ans = 0, prev = 0;
		while (ans < a.size() && tf <= s)
			prev = tf, tf += a[ans].f, ans++;
		if (tf <= s) cout << ans << " " << tf << endl;
		else cout << ans - 1 << " " << prev << endl;
		
		return 0;
	}
	if (tot >= 0) {
		for (auto &i : a)
			if (i.c > 0) {
				if (i.f <= s)
					cout << n << " " << i.f << endl;
				else
					cout << "0 0" << endl;
				return 0;
			}
	}

	ll prev = 0;
	pair<int, ll> best;
	int cnt = 0;
	ll tf = 0, at = 0;
	tot = abs(tot);
	while (at < a.size() && tf <= s) {
		if (a[at].c == 0) prev = tf, tf += a[at].f, cnt++;
		at++;
	}
	if (tf <= s)
		best = { cnt, tf };
	else
		best = { cnt - 1, prev };
	
	at = 0;
	for (; a[at].c == 0; at++);
	if (a[at].f > s) {
		cout << best.first << " " << best.second << endl;
		return 0;
	}
	tf = a[at].f, cnt = n - tot;
	for (int i = 0; i < a.size(); i++) {
		if (i != at) {
			if (a[i].f + tf > s) {
				if (best.first < min(n, cnt))
					best.first = min(n, cnt), best.second = tf;
				cout << best.first << " " << best.second << endl;
				return 0;
			}
			cnt++;
			tf += a[i].f;
		}
	}
	cout << n << " " << tf << endl;
}