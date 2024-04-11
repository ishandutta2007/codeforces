#include <bits/stdc++.h>
using namespace std;

int TC, A[105], B[105], C[105];

int main() {
	scanf("%d", &TC);
	while(TC--) {
		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) scanf("%d", &A[i]);
		for (int i = 0; i < N; i++) scanf("%d", &B[i]);
		for (int i = 0; i < N; i++) scanf("%d", &C[i]);
		vector<int> v;
		for (int i = 0; i < N; i++) {
			if (i == 0) v.push_back(A[i]);
			else if (i != N - 1) {
				if (A[i] == v.back()) v.push_back(B[i]);
				else v.push_back(A[i]);
			} else {
				if (A[i] != v.back() && A[i] != v[0]) v.push_back(A[i]);
				else if (B[i] != v.back() && B[i] != v[0]) v.push_back(B[i]);
				else v.push_back(C[i]);
			}
		}
		for (int i = 0; i < N; i++) {
			if (i) printf(" ");
			printf("%d", v[i]);
		}
		printf("\n");
	}
}