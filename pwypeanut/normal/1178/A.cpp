#include <bits/stdc++.h>
using namespace std;

int N, A[105];

int main() {
	scanf("%d", &N);
	int tsum = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
		tsum += A[i];
	}
	vector<int> ans;
	ans.push_back(1);
	int sum = A[0];
	for (int i = 1; i < N; i++) {
		if (2 * A[i] <= A[0]) {
			sum += A[i];
			ans.push_back(i+1);
		}
	}
	if (sum * 2 <= tsum) printf("0\n");
	else {
		printf("%d\n", ans.size());
		for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
		printf("\n");
	}
}