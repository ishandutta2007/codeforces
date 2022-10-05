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

int mx = 0;
string s;

bool check(int l, int r) {
	while (l < r) {
		if (s[l] != s[r]) return true;
		l++, r--;
	}
	return false;
}

int main() {
	fast;
	cin >> s;
	for (int i = 0; i < s.size(); i++) for (int j = i; j < s.size(); j++)
		if (check(i, j)) mx = max(mx, j - i + 1);
	finish(mx);
}