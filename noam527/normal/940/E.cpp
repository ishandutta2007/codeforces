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
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, c, a[100000];
ll dp[100000], mn[100000];

int main() {
	fast;
	cin >> n >> c;
	for (int i = 0; i < n; i++) cin >> a[i];
	if (n < c) {
		ll ans = 0;
		for (int i = 0; i < n; i++) ans += a[i];
		finish(ans);
	}

	multiset<int> s;
	ll sum = 0;
	for (int i = 0; i < c - 1; i++) s.insert(a[i]), sum += a[i];
	for (int i = c - 1; i < n; i++) {
		s.insert(a[i]);
		sum += a[i];
		mn[i] = sum - *s.begin();
		sum -= a[i - c + 1];
		s.erase(s.find(a[i - c + 1]));
	}
	
	dp[0] = a[0];
	for (int i = 1; i < c; i++) dp[i] = dp[i - 1] + a[i];
	dp[c - 1] = mn[c - 1];
	for (int i = c; i < n; i++)
		dp[i] = min(a[i] + dp[i - 1], mn[i] + dp[i - c]);
	cout << dp[n - 1] << endl;
}