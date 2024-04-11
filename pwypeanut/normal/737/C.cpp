#include <bits/stdc++.h>
using namespace std;

int N, K, A[200005], mis, blanks;
vector<int> v, not_filled;

int main() {
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	if (A[K - 1] != 0) mis++;
	for (int i = 0; i < N; i++) {
		if (i == K - 1) continue;
		if (A[i] == 0) {
			mis++;
			blanks++;
		} else v.push_back(A[i]);
	}
	sort(v.begin(), v.end());
	if (v.size() == 0) {
		printf("%d\n", mis);
		return 0;
	}
	for (int j = 1; j < v[0]; j++) not_filled.push_back(j);
	for (int i = 0; i < (int)v.size() - 1; i++) {
		for (int j = v[i] + 1; j < v[i + 1]; j++) not_filled.push_back(j);
	}
	reverse(not_filled.begin(), not_filled.end());
	for (int i = 0; i < min(blanks, (int)not_filled.size()); i++) not_filled.pop_back();
	if (not_filled.size() == 0) {
		printf("%d\n", mis);
		return 0;
	}
	while (true) {
		if (not_filled.size() == 0) {
			printf("%d\n", mis);
			return 0;
		}
		if (v.back() < not_filled.back()) {
			printf("%d\n", mis);
			return 0;
		}
		not_filled.pop_back();
		v.pop_back();
		mis++;
	}
}