#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
	scanf("%d", &N);
	if (N == 1) printf("1 1\n1\n");
	else printf("%d 2\n1 2\n", (N*2-2));
}