#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
typedef long double ld;

int N, M, X, ans = 4;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) {
			cin >> X;
			if (X) {
				if (i == 1 || i == N || j == 1 || j == M) ans = 2;
				else ans = min(ans, 4ll);
			}
		}
	cout << ans << '\n';
}