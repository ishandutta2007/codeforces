#include <bits/stdc++.h>
using namespace std;

int N, M, A[100005], count1[1005];

int qexp(int b, int p, int m) {
	if (p == 0) return 1 % m;
	else if (p == 1) return b % m;
	else if (p%2==0) {
		int x = qexp(b,p/2,m);
		return (x*x)%m;
	} else {
		int x = qexp(b, p/2, m);
		return (x*x*b)%m;
	}
}

int main() {
	scanf("%d%d", &N, &M);
	if (N > M) {
		printf("0\n");
		return 0;
	}
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	int ans = 1%M;
	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			ans *= abs(A[i]-A[j])%M;
			ans%=M;
		}
	}
	printf("%d\n", ans);
}