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

ll val1, sum = 0;
int n, m, q, l, r, x;
vector<int> a, b;
set<ll> val2;

ll solve() {
	auto it = val2.lower_bound(-val1);
	if (it == val2.end()) {
		auto temp = it;
		temp--;
		return abs(val1 + *temp);
	}
	if (it == val2.begin()) {
		if (val2.size() == 1) return abs(val1 + *it);
		auto temp = it;
		temp++;
		return min(abs(val1 + *it), abs(val1 + *temp));
	}

	auto itl = it, itr = it;
	itl--, itr++;
	if (itr == val2.end()) return min(abs(val1 + *it), abs(val1 + *itl));

	return min(min(abs(val1 + *itl), abs(val1 + *it)), abs(val1 + *itr));
}

int main() {
	fast;
	cin >> n >> m >> q;
	a.resize(n), b.resize(m);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];

	for (int i = 0; i < n; i++) {
		if (i & 1) sum -= a[i];
		else sum += a[i];
	}
	val1 = sum;
	sum = 0;
	for (int i = 0; i < n; i++) {
		if (i & 1) sum += b[i];
		else sum -= b[i];
	}
	val2.insert(sum);
	for (int i = 1; i <= m - n; i++) {
		sum += b[i - 1];
		sum *= -1;
		if (n & 1) sum -= b[i + n - 1];
		else sum += b[i + n - 1];
		val2.insert(sum);
	}

	cout << solve() << endl;
	while (q--) {
		cin >> l >> r >> x;
		if ((l & 1) && (r & 1)) val1 += x;
		if (!(l & 1) && !(r & 1)) val1 -= x;
		cout << solve() << endl;
	}
	return 0;
}