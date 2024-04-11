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
#include <fstream>
#include <random>
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
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int ans = 1;
int n, a[100000], pre[100000], suf[100000];

int main() {
	fast;
	cin >> n;
	if (n < 3) finish(1);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		pre[i] = a[i] - i;
		suf[i] = a[i] - (n - 1 - i);
	}
	for (int i = 1; i < n; i++) pre[i] = min(pre[i - 1], pre[i]);
	for (int i = n - 2; i >= 0; i--) suf[i] = min(suf[i + 1], suf[i]);
	for (int i = 1; i < n - 1; i++)
		ans = max(ans, min({ i + 1, n - i, a[i], pre[i - 1] + i, suf[i + 1] + (n - i - 1) }));
	cout << ans << endl;
}