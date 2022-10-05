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
vector<int> suf;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> s;
	n = s.size();
	suf.resize(n);
	suf[n - 1] = (s[n - 1] == ')' ? 1 : 0);
	for (int i = n - 2; i >= 0; i--)
		suf[i] = suf[i + 1] + (s[i] == ')' ? 1 : 0);
	vector<int> pos;
	bool start = true;
	for (int i = 0; i < n; i++) {
		if (pos.size() == suf[i])
			start = false;
		if (start) {
			if (s[i] == '(')
				pos.push_back(i);
		}
		else {
			if (s[i] == ')')
				pos.push_back(i);
		}
	}
	if (pos.size()) {
		cout << "1\n" << pos.size() << '\n';
		for (const auto &i : pos) cout << 1 + i << " "; cout << '\n';
	}
	else {
		cout << "0\n";
		return 0;
	}
}