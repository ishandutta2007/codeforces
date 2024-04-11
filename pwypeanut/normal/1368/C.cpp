#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
	scanf("%d", &N);
	printf("%d\n", N+1+N+2+N+1);
	for (int i = 0; i < N+1; i++) printf("%d %d\n", i, i+1);
	for (int i = 0; i < N+2; i++) printf("%d %d\n", i, i);
	for (int i = 0; i < N+1; i++) printf("%d %d\n", i+1, i);
}