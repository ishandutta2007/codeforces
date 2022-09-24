#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

const LL INF = 1e15;
const LL UB = 1e9;

int N, M, T[5010], L[5010], R[5010], D[5010];
LL A[5010], B[5010];

int main() {
    scanf("%d%d", &N, &M);
    for (int i=0; i<M; i++) {
	scanf("%d%d%d%d", T+i, L+i, R+i, D+i);
	L[i]--; R[i]--;
    }
    

    for (int i=0; i<N; i++) A[i] = INF;

    for (int i=M; i--;) {
	if (T[i] == 1) { // inc
	    for (int j=L[i]; j<=R[i]; j++) A[j] -= D[i];
	} else { // max query
	    for (int j=L[i]; j<=R[i]; j++) A[j] = min(A[j], (LL)D[i]);
	}
    }
    for (int i=0; i<N; i++) {
	A[i] = min(A[i], UB);
	A[i] = max(A[i], -UB);
	B[i] = A[i];
    }


    for (int i=0; i<M; i++) { // check
	if (T[i] == 1) { // inc
	    for (int j=L[i]; j<=R[i]; j++) A[j] += D[i];
	} else { // max query
	    bool ok = false;
	    for (int j=L[i]; j<=R[i]; j++) {
		if (A[j] == D[i]) ok = true;
	    }
	    if (!ok) {
		puts("NO");
		return 0;
	    }
	}
    }

    puts("YES");
    for (int i=0; i<N; i++) {
	cout << B[i] << (i==N-1 ? '\n' : ' ');
    }

    return 0;
}