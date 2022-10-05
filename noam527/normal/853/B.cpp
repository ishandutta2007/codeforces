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
const long long hs = 149;
//const double pi = acos(-1);
typedef long long ll;
typedef long double ldb;
using namespace std;

struct fli {
	int x, city, p;
	ll val;
	fli(int x = 0, int c = 0, int p = 0) : x(x), city(c), p(p) {};
	bool operator < (fli &a) {
		return x < a.x;
	}
};

int n, m, k;
vector<fli> a, b;

int main() {
	fast;
	cin >> n >> m >> k;
	for (int i = 0, d, f, t, c; i < m; i++) {
		cin >> d >> f >> t >> c;
		if (f == 0)
			b.push_back(fli(d, t, c));
		else
			a.push_back(fli(d, f, c));
	}
	sort(a.begin(), a.end()), sort(b.begin(), b.end());

	vector<int> prices(n + 1, -1);
	int badcnt = n;
	ll sum = 0;
	for (int i = 0; i < a.size(); i++) {
		if (prices[a[i].city] == -1) {
			badcnt--;
			sum += a[i].p;
			prices[a[i].city] = a[i].p;
		}
		if (a[i].p < prices[a[i].city]) {
			sum += (a[i].p - prices[a[i].city]);
			prices[a[i].city] = a[i].p;
		}
		if (badcnt) a[i].val = -1;
		else a[i].val = sum;
	}

	prices.assign(n + 1, -1);
	badcnt = n, sum = 0;
	for (int i = b.size() - 1; i >= 0; i--) {
		if (prices[b[i].city] == -1) {
			badcnt--;
			sum += b[i].p;
			prices[b[i].city] = b[i].p;
		}
		if (b[i].p < prices[b[i].city]) {
			sum += (b[i].p - prices[b[i].city]);
			prices[b[i].city] = b[i].p;
		}
		if (badcnt) b[i].val = -1;
		else b[i].val = sum;
	}

//	for (auto &i : a) cout << i.val << " "; cout << endl;
//	for (auto &i : b) cout << i.val << " "; cout << endl;

	ll ans = 9e18;
	int p1 = 0, p2 = 0;
	while (p1 < a.size() && p2 < b.size()) {
		if (b[p2].x - a[p1].x > k) {
			if (a[p1].val != -1 && b[p2].val != -1)
				ans = min(ans, a[p1].val + b[p2].val);
			p1++;
		}
		else p2++;
	}
	if (ans == 9e18) cout << -1 << endl;
	else cout << ans << endl;
}