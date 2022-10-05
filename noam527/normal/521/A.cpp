#include <bits/stdc++.h>
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
#define yesno(X) cout << ((X) ? "YES" : "NO") << endl
#define noyes(X) cout << ((X) ? "NO" : "YES") << endl
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n;
string s;
vector<int> a(26, 0);

int main() {
	fast;
	cin >> n >> s;
	for (const auto &i : s) a[i - 'A']++;
	sort(a.begin(), a.end());
	int p = 25;
	while (p >= 0 && a[p] == a.back()) p--;
	p = 25 - p;

	ll ans = 1;
	while (n--) ans = ans * p % md;
	finish(ans);
}