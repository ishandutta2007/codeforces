#include<cstdio>
#include<algorithm>

using namespace std;


int N, A[128];

int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d", A+i);
    sort(A, A+N);

    for (int i=1; i<=N; i++) {
	bool ok = true;
	for (int j=0; j<N; j++) {
	    if (A[j] < j/i) ok = false;
	}

	if (ok) {
	    printf("%d\n", i);
	    return 0;
	}
    }

    return 0;
}