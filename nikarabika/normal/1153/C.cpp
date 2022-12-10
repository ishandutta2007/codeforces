//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string s;
	cin >> s >> s;
	int must = sz(s) / 2 - count(all(s), '(');
	int sum = 0;
	if (must < 0)
		return cout << ":(", 0;
	for (int i = 0; i < sz(s); i++) {
		auto &c = s[i];
		if (c == '?') {
			c = (must > 0) ? '(' : ')';
			must--;
		}
		sum += (c == ')') ? -1 : +1;
		if (sum < 0 or (sum == 0 and i != sz(s) - 1))
			return cout << ":(", 0;
	}
	cout << s << endl;
	return 0;
}