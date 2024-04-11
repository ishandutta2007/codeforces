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

bool check(string s) {
	for (int x = 0; x < s.size(); x++)
		for (int k = 1; k < s.size() && x + 2 * k < s.size(); k++)
			if (s[x] == s[x + k] && s[x] == s[x + k + k]) return true;
	return false;
}
bool check(const string &s, int l, int r) {
	for (int x = l; x <= r; x++)
		for (int k = 1; x + k + k <= r; k++)
			if (s[x] == s[x + k] && s[x] == s[x + k + k]) return true;
	return false;
}

ll n;
string s;
ll ans = 0;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> s;
	n = s.size();
	for (int i = 0; i < n; i++) {
		int j = i;
		while (j < n && !check(s, i, j)) ans++, j++;
	}
	cout << n * (n + 1) / 2 - ans << '\n';
}