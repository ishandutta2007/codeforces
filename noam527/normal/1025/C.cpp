#include <bits/stdc++.h>
#define CHECK cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 1e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

string s;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> s;
	s += s;
	int ans = 0, p = 0;
	bool found = false;
	for (int i = 1; 2 * i < s.size(); i++)
		if (s[i - 1] == s[i]) found = true;
	if (!found) finish(s.size() / 2);
	for (int i = 0; i < s.size(); i++) {
		p = max(p, i);
		while (p + 1 < s.size() && s[p] != s[p + 1]) p++;
		ans = max(ans, p - i + 1);
	}
	finish(ans);
}