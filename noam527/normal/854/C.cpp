#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <time.h>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
const int md = 1e9 + 7;
const double pi = acos(-1);
typedef long long ll;
typedef long double ldb;
using namespace std;

int n, k, is = 0;
multimap<int, int> m;

int main() {
	fast;
	cin >> n >> k;
	if (k == n) k--, is = 1;

	vector<int> a(n), ans(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < k; i++) m.insert({ -a[i], i });
	int p = k + 1 + is;
	for (int i = k; i < n; i++) {
		m.insert({ -a[i], i });
		ans[m.begin()->second] = p++;
		m.erase(m.begin());
	}
	for (auto i = m.begin(); i != m.end(); i++) ans[i->second] = p++;

	ll tot = 0;
	for (int i = 0; i < n; i++) tot += (ll)(ans[i] - i - 1) * a[i];
	cout << tot << endl;
	for (auto i : ans) cout << i << " "; cout << endl;
}