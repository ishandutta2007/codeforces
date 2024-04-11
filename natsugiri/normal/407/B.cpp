#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
const LL MOD = 1000000007;
int N, P[1024];
int X[1024][1024];

int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
	scanf("%d", P+i);
	P[i]--;
    }

    for (int i=0; i<N; i++) {
	if (P[i] == i) X[i][i] = 1;
	else X[i][i] = (X[P[i]][i-1] + 2) % MOD;

	for (int j=0; j<i; j++) {
	    X[j][i] = (X[j][i-1] + 1LL + X[i][i]) % MOD;
	}
    }

    // for (int i=0; i<N; i++) {
    // 	for (int j=0; j<N; j++) {
    // 	    printf("%d %d : %d\n", i, j, (int)X[i][j]);
    // 	}
    // }
    
    printf("%d\n", (int)((X[0][N-1]+1)%MOD));
    return 0;
}