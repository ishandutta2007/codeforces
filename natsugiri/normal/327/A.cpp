#include<cstdio>
#include<algorithm>
using namespace std;


int N, A[128], sums[128], ans;
int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d", A+i);
    for (int i=0; i<N; i++) sums[i+1] = sums[i] + A[i];
    for (int i=0; i<N; i++) {
	for (int j=i; j<N; j++) {
	    ans = max(ans, sums[N] - 2*(sums[j+1]-sums[i]) + (j+1-i));
	}
    }
    printf("%d\n", ans);

    return 0;
}