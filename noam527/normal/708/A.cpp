#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define endl '\n'
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

string s;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> s;
	if (*max_element(s.begin(), s.end()) == 'a') {
		s.back() = 'z';
		finish(s);
	}
	int a = 0;
	for (auto &i : s) {
		if (a == 0 && i != 'a') a = 1;
		if (a == 1) {
			if (i != 'a') i--;
			else a = 2;
		}
	}
	finish(s);
}