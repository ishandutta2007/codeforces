#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long LL;

int N, A[500], M;
int p, sum;
int main() {
    scanf("%d", &N);
    M=2*N-1;
    for (int i=0; i<M; i++) scanf("%d", A+i);
    sort(A, A+M);
    if (N%2==1) {
	for (int i=0; i<M; i++) sum += (A[i]<0?-A[i]:A[i]);
    } else {
	for (int i=0; i<M; i+=2) {
	    if (i+1<M && A[i]+A[i+1]<0) sum -= A[i]+A[i+1];
	    else sum += A[i]+A[i+1];
	}
    }
    printf("%d", sum);
    return 0;
}