#include<cstdio>

int main() {
    int N, K; scanf("%d%d", &N, &K);
    if (N*(N-1)/2>K) {
	for (int i=0; i<N; i++) {
	    printf("0 %d\n", i);
	}
    } else {
	puts("no solution");
    }

    return 0;
}