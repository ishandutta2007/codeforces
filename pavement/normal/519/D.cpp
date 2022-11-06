#include <bits/stdc++.h>
using namespace std;
#define int long long

int T, V[30], P[100005];
string S;
map<int, int> M[30];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < 26; i++) cin >> V[i];
	cin >> S;
	for (int i = 0; i < S.size(); i++)
		P[i + 1] = P[i] + V[S[i] - 'a'];
	for (int i = 1; i <= S.size(); i++) {
		T += M[S[i - 1] - 'a'][P[i - 1]];
		M[S[i - 1] - 'a'][P[i]]++;
	}
	cout << T << '\n';
}