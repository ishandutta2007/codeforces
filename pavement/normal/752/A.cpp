#include <bits/stdc++.h>
using namespace std;
#define int long long

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, M, K;
	cin >> N >> M >> K;
	int col = M * 2, u = 1;
	while (K > col)
		K -= col, u++;
	cout << u << ' ' << (K + 1) / 2 << ' ' << (K & 1 ? "L" : "R") << '\n';
}