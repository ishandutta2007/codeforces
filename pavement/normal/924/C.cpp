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

int N, D, M[100005], T[100005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> M[i];
	for (int i = 1; i <= N; i++)
		T[i] = max(T[i - 1], M[i] + 1);
	for (int i = N; i >= 1; i--)
		T[i] = max({T[i], T[i + 1] - 1, M[i] + 1});
	for (int i = 1; i <= N; i++) D += T[i] - M[i] - 1;
	cout << D << '\n';
}