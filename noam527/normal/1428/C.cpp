#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 3e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

string s;

void solve() {
	cin >> s;
	string st = "";
	for (auto c : s) {
		if (c == 'A') st.push_back(c);
		else {
			if (st.size() == 0) st.push_back(c);
			else st.pop_back();
		}
	}
	cout << st.size() << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}