#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;


int main() {
    int T, N, P;
    scanf("%d", &T);
    for (;T--;) {
	scanf("%d%d", &N, &P);
	for (int i=0; i<N; i++) { // 2N
	    printf("%d %d\n", i+1, (i+1)%N+1);
	    printf("%d %d\n", i+1, (i+2)%N+1);
	}

	for (int d=3; P; d++) {
	    for (int i=0; i<N && P; i++) {
		printf("%d %d\n", i+1, (i+d)%N+1);
		P--;
	    }
	}
    }
    return 0;
}