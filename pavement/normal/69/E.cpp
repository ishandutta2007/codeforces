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

int N, K, A[100005];
set<int> S;
map<int, int> M;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i < K; i++) {
		if (M[A[i]] == 1) S.erase(A[i]);
		M[A[i]]++;
		if (M[A[i]] == 1) S.insert(A[i]);
	}
	for (int i = K; i <= N; i++) {
		// erase element i - K
		if (i > K) {
			if (M[A[i - K]] == 1) S.erase(A[i - K]);
			M[A[i - K]]--;
			if (M[A[i - K]] == 1) S.insert(A[i - K]);
		}
		// include element i
		if (M[A[i]] == 1) S.erase(A[i]);
		M[A[i]]++;
		if (M[A[i]] == 1) S.insert(A[i]);
		if (S.empty()) cout << "Nothing\n";
		else cout << *S.rbegin() << '\n';
	}
}