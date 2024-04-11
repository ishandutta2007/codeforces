#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define ppb pop_back
#define eb emplace_back
typedef long double ld;

int T, M, N, A[105], B, C, X, Y, Z;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		M = 0;
		map<int, int> cnt;
		cin >> N >> X;
		for (int i = 1; i <= N; i++) cin >> A[i];
		for (int i = 1; i <= 200; i++) {
			cnt.clear();
			for (int j = 1; j <= N; j++)
				if (A[j] <= i) cnt[A[j]] = 1;
			if (i - cnt.size() <= X) M = max(M, i);
		}
		cout << M << '\n';
	}
}