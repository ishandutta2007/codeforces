#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, M, A[105], B[105];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	cin >> M;
	for (int i = 1; i <= M; i++) cin >> B[i];
	cout << *max_element(A + 1, A + 1 + N) << ' ' << *max_element(B + 1, B + 1 + M) << '\n';
}