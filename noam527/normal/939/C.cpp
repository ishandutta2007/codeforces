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

int n, a[100001], s[200001], p, f, ans = 1e9, mx = -1e9;

int main() {
	fast;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	s[0] = a[0];
	for (int i = 1; i < n; i++) s[i] = s[i - 1] + a[i];
	for (int i = n; i < 2 * n; i++) s[i] = s[i - 1] + a[i - n];

	cin >> p >> f;
	--p, --f;
	for (int i = 0; i < n; i++) {
		int st = (p - i + n) % n;
		if (st == 0) {
			if (mx < s[st + f - p - 1])
				mx = s[st + f - p - 1], ans = i;
		}
		else {
			if (mx < s[st + f - p - 1] - s[st - 1])
				mx = s[st + f - p - 1] - s[st - 1], ans = i;
		}
	}
	cout << ans + 1 << endl;
}