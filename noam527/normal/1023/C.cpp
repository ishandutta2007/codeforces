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

int n, k, sum = 0, tot = 0;
string s, t;

int main() {
	fast;
	cin >> n >> k >> s;
	for (const auto &c : s) {
		if (c == '(') {
			if (sum + 1 <= k - tot - 1) {
				sum++;
				tot++;
				t.push_back(c);
			}
		}
		else {
			if (tot < k && sum > 0) {
				sum--;
				tot++;
				t.push_back(c);
			}
		}
	}
	finish(t);
}