#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n;
string s;
vector<int> p;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> s;
	p.resize(n);
	for (int i = 0; i < n; i++)
		p[i] = (s[i] == '(' ? 1 : -1);
	for (int i = 1; i < n; i++) p[i] += p[i - 1];
	if (p.back() != 0)
		finish(-1);
	int lst = -1, ans = 0;
	for (int i = 0; i < n; i++) {
		if (p[i] >= 0) {
			if (i - lst > 1)
				ans += i - lst;
			lst = i;
		}
	}
	cout << ans << endl;
}