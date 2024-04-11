#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#include <queue>
#define last(x, y) (x)[(x).size() - (y)]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 199;
//const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, a[200002], l[200002], r[200002], ans[200002] = {};
vector<int> s;

int main() {
	fast;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) {
		while (s.size() && a[s.back()] > a[i]) s.pop_back();
		if (s.size()) l[i] = s.back();
		else l[i] = -1;
		s.push_back(i);
	}
	s.clear();
	for (int i = n - 1; i >= 0; i--) {
		while (s.size() && a[s.back()] >= a[i]) s.pop_back();
		if (s.size()) r[i] = s.back();
		else r[i] = n;
		s.push_back(i);
	}
	for (int i = 0; i < n; i++) ans[r[i] - l[i] - 2] = max(ans[r[i] - l[i] - 2], a[i]);
	for (int i = n - 2; i >= 0; i--) ans[i] = max(ans[i], ans[i + 1]);
	for (int i = 0; i < n; i++) cout << ans[i] << " "; cout << endl;
}