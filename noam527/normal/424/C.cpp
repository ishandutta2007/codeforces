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
const long long hs = 137;
//const double pi = acos(-1);
typedef long long ll;
typedef long double ldb;
using namespace std;

ll ans = 0;
int n;
vector<int> a(1e6 + 3, 0);

void add(int l, int r) {
	a[l]++, a[r + 1]--;
}

void add(int x) {
	int val = n / x, m = n % x;
	if (val & 1)
		add(0, 0), add(m + 1, x - 1);
	else
		add(1, m);
}

int main() {
	fast;
	cin >> n;
	for (int i = 0, x; i < n; i++)
		cin >> x, ans ^= x;
	for (int i = 2; i <= n; i++) add(i);
	for (int i = 1; i < a.size(); i++) a[i] += a[i - 1];
//	for (int i = 0; i <= n + 1; i++) cout << a[i] << " "; cout << endl;
	for (int i = 0; i < a.size(); i++)
		if (a[i] & 1) ans ^= i;
	cout << ans << endl;
}