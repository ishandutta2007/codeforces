#include <bits/stdc++.h>
using namespace std;
int main () {
	int T; cin >> T;
	while (T--) {
		int n, k; cin >> n >> k;
		long long need = (n + k - 1ll) / k * k;
		need = (need + n - 1ll) / n;
		cout << need << endl;
	}
	return 0;
}