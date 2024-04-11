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

int h(char c) {
	if (c == 'L') return 0;
	if (c == 'S') return 1;
	return 2;
}

int n;
int c[4][3] = {};
string s;

int main() {
	fast;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s, c[s.size() - 1][h(s.back())]++;
	for (int i = 0; i < n; i++)
		cin >> s, c[s.size() - 1][h(s.back())]--;
	int tot = 0;
	for (int i = 0; i < 4; i++) for (int j = 0; j < 3; j++)
		tot += abs(c[i][j]);
	finish(tot / 2);
}