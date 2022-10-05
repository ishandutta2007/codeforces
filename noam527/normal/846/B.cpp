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

int n, k, m, ans = 0, sum = 0;
vector<int> a;

int best(int c) {
	int rtn = 0, i = 0, m2 = m;
	while (i < c && m2 >= sum) m2 -= sum, i++, rtn += k + 1;

	i = 0;
	while (i < k && m2 >= (n - c) * a[i]) m2 -= (n - c) * a[i], i++, rtn += (n - c);

	if (i == k) return rtn;
	return rtn + (m2 / a[i]);
}

int main() {
	fast;
	cin >> n >> k >> m;
	a.resize(k);
	for (int i = 0; i < k; i++) cin >> a[i], sum += a[i];
	sort(a.begin(), a.end());
	int ans = -1;
	for (int i = 0; i <= n; i++) ans = max(ans, best(i));
	cout << ans << endl;
}