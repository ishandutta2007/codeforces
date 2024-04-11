#include <bits/stdc++.h>
using namespace std;

int N;
long long K, A[100005];
map<long long, int> M;

int main() {
	scanf("%d%lld", &N, &K);
	for (int i = 0; i < N; i++) scanf("%lld", &A[i]);
	for (int i = 1; i < N; i++) A[i] += A[i - 1];
	long long cur = 1;
	long long ans = 0;
	while (cur <= 1000000000000000ll) {
		// find segments of cur
		M.clear();
		M[0] = 1;
		for (int i = 0; i < N; i++) {
			ans += M[A[i] - cur];
			M[A[i]]++;
		}
		
		cur *= K;
		if (cur == 1) break;
	}
	printf("%lld\n", ans);
}