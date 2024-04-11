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
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-7, pi = acos(-1);
using namespace std;

int n;
vector<int> a, need;

ll ans = 0;

int main() {
	fast;
	cin >> n;
	a.resize(n);
	for (auto &i : a) cin >> i;
	need.resize(n);
	int mx = 0;
	for (int i = n - 1; i >= 0; i--) {
		mx = max(--mx, a[i]);
		need[i] = mx;
	}
//	for (const auto &i : need) cout << i << " "; cout << endl;
	int have = 0;
	for (int i = 0; i < n; i++) {
		if (need[i] >= have) {
			ans += (have - a[i]);
			have++;
		}
		else ans += (have - a[i] - 1);
	}
	//ans += (have - a.back() - 1);
	cout << ans << endl;
}