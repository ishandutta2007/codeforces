#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, T, Y, C[5];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1, X; i <= N; i++) {
		cin >> X;
		if (X == 4) T++;
		else C[X]++;
	}
	T += min(C[1], C[3]);
	Y = min(C[1], C[3]);
	C[1] -= Y;
	C[3] -= Y;
	T += C[3] + C[2] / 2;
	if (C[2] & 1) {
		T++;
		C[1] = max(0ll, C[1] - 2);
	}
	T += C[1] / 4 + !!(C[1] % 4);
	cout << T << '\n';
}