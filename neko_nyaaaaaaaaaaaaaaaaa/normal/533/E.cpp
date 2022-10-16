#include <bits/stdc++.h>
using namespace std;

int check(string a, string b) {
      a.erase(0, 1);
      b.pop_back();
      return a == b;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	string a, b; cin >> a >> b;
	while (a.back() == b.back()) {
            a.pop_back();
            b.pop_back();
	}
	reverse(a.begin(), a.end()); reverse(b.begin(), b.end());
	while (a.back() == b.back()) {
            a.pop_back();
            b.pop_back();
	}

	cout << check(a, b) + check(b, a);

	return 0;
}