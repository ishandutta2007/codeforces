#include <bits/stdc++.h>
 
using namespace std;

const int dd = (int)1e5 + 1;

int A[dd], dp[dd], n, k;

pair<int, int> get(int x) {
	return { max(0, x - k), min(n - 1, x + k) };
}

int per(int a, int b) {
	auto q = get(a), w = get(b);
	return max(0, min(q.second, w.second) - max(q.first, w.first) + 1);
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d", &A[i]);

	for (int i = 0; i < n; ++i) {
		dp[i] = get(i).second - get(i).first + 1;
		if (A[i] != 0)
			dp[i] += dp[A[i] - 1] - per(A[i] - 1, i);
		printf("%d ", dp[i]);
	}
    return 0;
}