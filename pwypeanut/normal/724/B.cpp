#include <bits/stdc++.h>
using namespace std;

int N, M, a[25][25];
int model[25];
bool success;

void attempt() {
	for (int i = 0; i < N; i++) {
		int wrongs = 0;
		for (int j = 0; j < M; j++) {
			if (model[j] != a[i][j]) wrongs++;
		}
		if (wrongs == 0 || wrongs == 2) continue;
		return;
	}
	success = 1;
	return;
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) scanf("%d", &a[i][j]);
	for (int i = 0; i < M; i++) model[i] = i + 1;
	attempt();
	for (int i = 0; i < M; i++) {
		for (int j = i + 1; j < M; j++) {
			swap(model[i], model[j]);
			attempt();
			swap(model[i], model[j]);
		}
	}
	if (success) printf("YES\n");
	else printf("NO\n");
}