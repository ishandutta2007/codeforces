#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, K, T;
char S[200005], y;
bool C[30];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> S[i];
	while (K--) {
		cin >> y;
		C[y - 'a'] = 1;
	}
	for (int i = 1; i <= N; i++)
		if (C[S[i] - 'a']) S[i] = 1;
		else S[i] = 0;
	int acc = 0;
	for (int i = 1; i <= N; i++) {
		if (S[i] == 0) {
			T += acc * (acc + 1) / 2;
			acc = 0;
		} else acc++;
	}
	T += acc * (acc + 1) / 2;
	cout << T << '\n';
}