#include <bits/stdc++.h>
using namespace std;
#define int long long

int C;
string S, T;
set<int> Y[35];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> S >> T;
	for (int i = 0; i < S.size(); i++) {
		Y[S[i] - 'a'].insert(T[i] - 'a');
		Y[T[i] - 'a'].insert(S[i] - 'a');
	}
	for (int i = 0; i < 26; i++)
		if (Y[i].size() > 1) return cout << "-1\n", 0;
		else if (Y[i].size() == 1 && i < *Y[i].begin()) C++;
	cout << C << '\n';
	for (int i = 0; i < 26; i++)
		if (Y[i].size() == 1 && i < *Y[i].begin()) cout << char(i + 'a') << ' ' << char(*Y[i].begin() + 'a') << '\n';
}