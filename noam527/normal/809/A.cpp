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
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n;
ll curr = 0, tot = 0;
vector<ll> a;

int main() {
	fast;
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	for (int i = 1, pw = 1; i < n; i++, pw = (2 * pw) % md)
		curr = ((curr + (a[i] - a[i - 1]) * (pw - 1) % md) * 2 + a[i] - a[i - 1]) % md, tot = (tot + curr) % md;
	cout << tot << endl;
}