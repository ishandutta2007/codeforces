#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

int A[111], N, K;
int main() {
    scanf("%d%d", &N, &K);
    for (int i=0; i<N; i++) scanf("%d", A+i);
    nth_element(A, A+N-K, A+N);
    printf("%d\n", A[N-K]);
    return 0;
}