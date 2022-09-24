#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

int N, K;
char S[111];
int main() {
    scanf("%d%d%s", &N, &K, S);

    if (N < K*2) { 
	for (;K < N; K++) puts("RIGHT");
	while (K>1) {
	    K--;
	    printf("PRINT %c\n", S[K]);
	    puts("LEFT");
	}
	printf("PRINT %c\n", S[0]);
    } else {
	for (;K>1; K--) puts("LEFT");
	while (K<N) {
	    printf("PRINT %c\n", S[K-1]);
	    puts("RIGHT");
	    K++;
	}
	printf("PRINT %c\n", S[N-1]);
    }
    

    return 0;
}