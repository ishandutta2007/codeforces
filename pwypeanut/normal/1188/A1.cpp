#include <bits/stdc++.h>
using namespace std;

int arr[100005];

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N-1; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		arr[a]++;
		arr[b]++;
	}
	bool ans = true;
	for (int i = 1; i <= N; i++) if (arr[i] == 2) ans = false;
	printf("%s\n", ans ? "YES" : "NO");
}