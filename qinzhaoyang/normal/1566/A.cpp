#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main() {
	int T, n, s;
	ios::sync_with_stdio(false);
	for (cin >> T; T; T--) {
		cin >> n >> s;
		if (n == 1) cout << s << endl;
		else if(n == 2)cout << s / 2 << endl;
		else {
			int x = (n + 1) / 2;
			cout << s / (n - x + 1) << endl;
		}
	}
	return 0;
}