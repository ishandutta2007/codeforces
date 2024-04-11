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

int N, A[100005];
set<int> S;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i], S.insert(A[i]);
	if (S.size() > 3) return cout << "NO\n", 0;
	if (S.size() == 3) {
		if (abs(*S.begin() - *(++S.begin())) == abs(*(++S.begin()) - *S.rbegin())) cout << "YES\n";
		else cout << "NO\n";
	} else cout << "YES\n";
}