#include <bits/stdc++.h>
using namespace std;

int N, K, A[100005], at[100005];
long long ans = 0;
priority_queue< pair<long long, int> > PQ;

long long cost(int len, int k) {
	int bigs = len % k;
	long long ans = (long long)bigs * (len / k + 1) * (len / k + 1) + (long long)(k - bigs) * (len / k) * (len / k);
	return ans;
}

int main() {
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	for (int i = 0; i < N; i++) ans += (long long)A[i] * A[i];
	for (int i = 0; i < N; i++) at[i] = 1;
	for (int i = 0; i < N; i++) PQ.push(make_pair(cost(A[i], 1) - cost(A[i], 2), i));
	for (int i = 0; i < K - N; i++) {
		pair<long long, int> p = PQ.top();
		PQ.pop();
		ans -= p.first;
		PQ.push(make_pair(cost(A[p.second], at[p.second] + 1) - cost(A[p.second], at[p.second] + 2), p.second));
		at[p.second]++;
	}
	printf("%lld\n", ans);
}