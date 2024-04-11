#include <bits/stdc++.h>
using namespace std;

int N;
long long X[5005], Y[5005];
vector<int> V;

bool acute(int a, int b, int c) {
	long long ac = (X[c] - X[a]) * (X[c] - X[a]) + (Y[c] - Y[a]) * (Y[c] - Y[a]);
	long long ab = (X[b] - X[a]) * (X[b] - X[a]) + (Y[b] - Y[a]) * (Y[b] - Y[a]);
	long long bc = (X[c] - X[b]) * (X[c] - X[b]) + (Y[c] - Y[b]) * (Y[c] - Y[b]);
	return ac < ab + bc;
}

bool cmp(int x, int y) {
	if (X[x] != X[y]) return X[x] < X[y];
	else return Y[x] < Y[y];
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%lld%lld", &X[i], &Y[i]);
	for (int i = 0; i < N; i++) V.push_back(i);
	sort(V.begin(), V.end(), cmp);
	for (int j = 0; j < N; j++) {
		bool allacute = 0;
		for (int i = 0; i < N - 2; i++) {
			if (!acute(V[i], V[i+1], V[i+2])) {
				swap(V[i+1], V[i+2]);
				allacute = 1;
			}
		}
		if (!allacute) break;
	}
	bool fail = 0;
	for (int i = 0; i < N - 2; i++) {
		if (!acute(V[i], V[i+1], V[i+2])) fail = 1;
	}
	if (fail) {
		printf("-1\n");
		return 0;
	}
	for (int i = 0; i < N; i++) {
		if (i) printf(" ");
		printf("%d", V[i]+1);
	}
	printf("\n");
}