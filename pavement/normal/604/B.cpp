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

int N, K, T, A[100005], mat[100005];
bool V[100005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	K = min(N, K);
	int tk = 0;
	for (int i = N; i >= 1; i--) {
		if (i & 1) {
			if ((i + 1) / 2 <= K) tk++, K--;
			else break;
		} else {
			if (i / 2 < K) tk++, K--;
			else break;
		}
	}
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = N - tk + 1; i <= N; i++) T = max(T, A[i]);
	for (int i = 1, idx = N - tk; i <= N - tk; i++)
		mat[i] = idx--;
	for (int i = 1; i <= N - tk; i++) {
		V[i] = 1;
		if (!V[mat[i]]) T = max(T, A[i] + A[mat[i]]);
	}
	cout << T << '\n';
}