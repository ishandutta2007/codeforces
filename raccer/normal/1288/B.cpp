#include <bits/stdc++.h>
using namespace std;
int main () {
	int T; cin >> T;
	while (T--) {
		long long a, b; cin >> a >> b;
		long long pw = 10, cnt = 0;
		while (pw - 1 <= b) pw *= 10, cnt++;
		cout << a * cnt << endl;
	}
	return 0;
}