#include <bits/stdc++.h>
using namespace std;
#define int long long
 
bool b[35];
 
main() {
	int M, N, r;
	cin >> M >> N;
	for (int i = 1; i <= N; i++) {
		cout << i << endl;
		cin >> r;
		if (r == 0) exit(0);
		b[i] = r == -1;
	}
	int lo = 1, hi = M, idx = 1;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		cout << mid << endl;
		cin >> r;
		if (r == 0) exit(0);
		if (!b[idx++]) r *= -1;
		if (r == 1) hi = mid - 1;
		else lo = mid + 1;
		if (idx == N + 1) idx = 1;
	}
	assert(false);
}