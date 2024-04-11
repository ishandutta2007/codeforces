#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

int N, M, K;
int E[20010], C[10];
bool A[20010][10];

int main() {
    scanf("%d%d%d", &N, &M, &K);
    for (int i=0; i<N; i++) {
	for (int j=0; j<M; j++) {
	    int x;
	    scanf("%d", &x);
	    A[i][j] = x;
	}
    }

    for (int i=0; i<K; i++) {
	int a, b;
	scanf("%d%d", &a, &b);
	a--; b--;
	E[a]++; C[b]++;
    }

    for (int i=0; i<N; i++) {
	int cnt = -E[i];
	for (int j=0; j<M; j++) if (A[i][j]) cnt += C[j];

	printf("%d%c", cnt, i==N-1 ? '\n' : ' ' );
    }

    return 0;
}