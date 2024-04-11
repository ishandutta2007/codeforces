#include <bits/stdc++.h>
using namespace std;

int K, mx;

int main() {
	scanf("%d", &K);
	mx = 25;
	for (int i = 0; i < K; i++) {
		int x;
		scanf("%d", &x);
		mx = max(mx, x);
	}
	printf("%d\n", mx - 25);
}