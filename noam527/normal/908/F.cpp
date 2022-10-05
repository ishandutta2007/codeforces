#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#include <stack>
#include <queue>
#include <random>
#include <fstream>
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

const int inf = 1e9 + 10;

ll ans = 0;
int n;
char c;
vector<pair<int, int>> a;

ll calc(int st, int en) {
	if (st + 1 == en) return a[st].first - a[en].first;
	static int l[2], mxd[2];
	l[0] = l[1] = a[st].first;
	mxd[0] = mxd[1] = -inf;
	for (int i = st + 1; i < en; i++) {
		mxd[a[i].second] = max(mxd[a[i].second], a[i].first - l[a[i].second]);
		l[a[i].second] = a[i].first;
	}
	mxd[0] = max(mxd[0], a[en].first - l[0]);
	mxd[1] = max(mxd[1], a[en].first - l[1]);
//	cout << mxd[0] << " " << mxd[1] << endl;
	return a[en].first - a[st].first - mxd[0] - mxd[1];
}

int main() {
	fast;
	cin >> n;
	if (n == 1) finish(0);
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> c;
		if (c == 'G') a[i].second = -1;
		else if (c == 'B') a[i].second = 0;
		else a[i].second = 1;
	}
	
	int mn[2] = { inf, inf }, mx[2] = { -inf, -inf };
	
	for (int i = 0; i < n; i++) {
		if (a[i].second == -1) {
			for (int j = 0; j < 2; j++)
				mn[j] = min(mn[j], a[i].first), mx[j] = max(mx[j], a[i].first);
		}
		else {
			mn[a[i].second] = min(mn[a[i].second], a[i].first);
			mx[a[i].second] = max(mx[a[i].second], a[i].first);
		}
	}
	if (mx[0] != -inf) ans += mx[0] - mn[0];
	if (mx[1] != -inf) ans += mx[1] - mn[1];

	ll val;
	int l = -1;
	while (++l < n && a[l].second != -1);
	for (int i = l + 1; i < n; i++) {
		if (a[i].second == -1) {
			val = calc(l, i);
			if (val < 0) ans += val;
			l = i;
		}
	}
	cout << ans << endl;
}