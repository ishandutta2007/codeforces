#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

int N, M, A[3010];
int main() {
    scanf("%d%d", &N, &M);
    for (int i=0; i<M; i++) scanf("%d", A+i);
    sort(A, A+M);
    
    bool yes = true;
    for (int i=0; i<M; i++) if (A[i] == 1 || A[i] == N) yes = false;

    for (int i=0; i<M-2; i++) {
	if (A[i+1]-A[i] == 1 &&
	    A[i+2]-A[i+1] == 1) yes = false;
    }

    puts(yes ? "YES" : "NO");

    return 0;
}