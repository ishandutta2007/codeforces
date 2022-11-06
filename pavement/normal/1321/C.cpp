#include <bits/stdc++.h>
using namespace std;
#define int long long
 
int N, T;
char S[105];
bool C[105];
set<pair<char, int> > pq;

main() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> S[i];
	for (int i = 1; i <= N; i++) {
		if (S[i - 1] == S[i] - 1)
			pq.emplace(S[i], i);
		else if (S[i + 1] == S[i] - 1)
			pq.emplace(S[i], i);
	}
	while (!pq.empty()) {
		auto a = *pq.rbegin();
		pq.erase(--pq.end());
		T++;
		C[a.second] = 1;
		int L = -1, R = -1;
		for (int i = a.second; i >= 1; i--)
			if (!C[i]) {
				L = i;
				break;
			}
		for (int i = a.second; i <= N; i++)
			if (!C[i]) {
				R = i;
				break;
			}
		if (L == -1 || R == -1) continue;
		if (S[L] == S[R] - 1) pq.emplace(S[R], R);
		else if (S[L] - 1 == S[R]) pq.emplace(S[L], L);
	}
	cout << T << '\n';
}