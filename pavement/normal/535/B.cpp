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

int N, T;
string S;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	S = to_string(N);
	for (int i = 1; i < S.size(); i++)
		T += 1ll<<i;
	for (int i = 0; i < S.size(); i++)
		if (S[i] == '7') T += 1ll<<(S.size() - i - 1);
	cout << T + 1 << '\n';
}