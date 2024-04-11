#include <bits/stdc++.h>
using namespace std;

int N, K, A[400005], l[400005], nxt[400005];
bool hasbook[400005];
multiset< pair<int, int> > S;

int main() {
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	memset(l, 63, sizeof(l));
	for (int i = N - 1; i >= 0; i--) {
		nxt[i] = l[A[i]];
		l[A[i]] = i;
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (hasbook[A[i]]) {
			S.erase(S.find(make_pair(i, A[i])));
			S.insert(make_pair(nxt[i], A[i]));
		} else {
			if (S.size() >= K) {
				pair<int, int> p = *S.rbegin();
				S.erase(--S.end());
				hasbook[p.second] = 0;
			}
			S.insert(make_pair(nxt[i], A[i]));
			hasbook[A[i]] = 1;
			ans++;
		}
	}
	printf("%d\n", ans);
}