#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 31607;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

int n;
string s;

void solve() {
	cin >> n >> s;
	string t = s;
	sort(t.begin(), t.end());
	int cnt = 0;
	for (int i = 0; i < n; i++)
		if (s[i] != t[i]) cnt++;
	cout << cnt << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	//srand(time(NULL));
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}