#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define ppb pop_back
#define eb emplace_back
typedef long double ld;

int N, Q, TT, A[200005], L[200005], R[200005], D[200005], O[200005];
pair<int, int> T[200005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) cin >> A[i];
	sort(A + 1, A + 1 + N, greater<int>());
	for (int i = 1; i <= Q; i++) {
		cin >> L[i] >> R[i];
		D[L[i]]++;
		D[R[i] + 1]--;
	}
	for (int i = 1, pf = 0; i <= N; i++) {
		pf += D[i];
		T[i] = mp(pf, i);
	}
	sort(T + 1, T + 1 + N, greater<pair<int, int> >());
	for (int i = 1; i <= N; i++)
		O[T[i].second] = A[i];
	for (int i = 1; i <= N; i++) O[i] += O[i - 1];
	for (int i = 1; i <= Q; i++)
		TT += O[R[i]] - O[L[i] - 1];
	cout << TT << '\n';
}