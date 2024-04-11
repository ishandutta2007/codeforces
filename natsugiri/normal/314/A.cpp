#include<cstdio>
#include<algorithm>
using namespace std;

typedef long long LL;

int N, K, A[200010];

int main() {
    scanf("%d%d", &N, &K);
    for (int i=0; i<N; i++) scanf("%d", A+i);

    LL cnt=0, sum=0;
    for (int i=1; i<N; i++) {
	LL I=i-cnt+1, y= -(I-1)*(N-cnt-I)*A[i];
	//printf("%d %lld\n", i+1, sum+x+y);
	if (sum+y<K) {
	    printf("%d\n", i+1);
	    cnt++;
	} else {
	    sum += A[i]*(I-1);
	}
    }

    return 0;
}