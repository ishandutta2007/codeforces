#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long LL;

int N, S[600000];

int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d", S+i);

    sort(S, S+N);

    int cnt = 0, p=1;
    for (int i=0; i<N/2; i++) {
	int k = lower_bound(S+p, S+N, S[i]*2) - S;

	if (k==N) break;
	cnt++;
	p = k+1;
	if (p>=N) break;
    }
    printf("%d\n", N-cnt);

    return 0;
}