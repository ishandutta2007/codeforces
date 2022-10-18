#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc; cin >> tc;
	while (tc--) {
		int n; cin >> n;
		string res = "";
		for (int i = 0; i < n/3; i++) res += "21";
		if (n%3 == 1) res = "1" + res;
		if (n%3 == 2) res = res + "2";
		cout << res << '\n';
	}
}