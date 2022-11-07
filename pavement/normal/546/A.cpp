#include <bits/stdc++.h>
using namespace std;

int main() {
	int k, w, n;
	cin >> k >> w >> n;
	for (int i = 1; i <= n; i++) {
		w -= k * i;
	}
	if (w > 0) cout << 0;
	else cout << abs(w);
}