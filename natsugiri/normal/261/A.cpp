#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int M, N, A[100010];

int main() {
    scanf("%d", &M);
    int mi=1e6;
    for (int i=0; i<M; i++) {
	int q;
	scanf("%d", &q);
	mi=min(mi, q);
    }
    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d", A+i);

    sort(A, A+N);
    int cst=0;
    for (int i=N-1; i>=0; i-=mi+2) {
	for (int j=0; j<mi && i-j>=0; j++) cst+=A[i-j];
    }
    printf("%d\n", cst);

    return 0;
}