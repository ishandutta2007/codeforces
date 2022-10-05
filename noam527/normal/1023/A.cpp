#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, m;
string s, t;

int main() {
	fast;
	cin >> n >> m >> s >> t;
	if (find(s.begin(), s.end(), '*') == s.end()) {
		if (s == t) finish("YES");
		finish("NO");
	}
	if (n - 1 > m) finish("NO");
	int st, en;
	st = 0;
	while (s[st] != '*' && s[st] == t[st]) st++;
	en = 0;
	while (s[n - 1 - en] != '*' && s[n - 1 - en] == t[m - 1 - en]) en++;
	if (st + en == n - 1) finish("YES");
	finish("NO");
}