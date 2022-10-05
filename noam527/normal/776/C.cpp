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

int n, k, a[100000];
vector<ll> pw;
map<ll, int> m;

ll s = 0, ans = 0;

int main() { 
	fast;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	if (abs(k) > 1)
		for (ll i = 1; abs(i) <= 1e17; i *= k) pw.push_back(i);
	else {
		if (k == -1) pw.push_back(-1);
		pw.push_back(1);
	}

	m[0] = 1;
	for (int i = 0; i < n; i++) {
		s += a[i];
		for (const auto &j : pw) ans += m[s - j];
		m[s]++;
	}
	cout << ans << endl;
}