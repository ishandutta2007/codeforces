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

int N, M, K, T, A[200005];
deque<int> D;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) cin >> A[i];
	sort(A + 1, A + 1 + N);
	for (int i = 1, r = 1; i <= N; i++) {
		while (r <= N && A[r] - A[i] < M) D.pb(r++);
		while (!D.empty() && D.front() < i) D.ppf();
		while (D.size() >= K) D.ppb(), T++;
	}
	cout << T << '\n';
}