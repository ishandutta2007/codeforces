#include<cstdio>

int N, A[100010];
int main() {
    scanf("%d", &N);
    if (N%4<2) {
	for (int i=1; i<=N/2; i+=2) {
	    A[i]=i+1;
	    A[i+1]=N-i+1;
	    A[N-i+1]=N-i;
	    A[N-i]=i;
	}
	if (N%2==1) A[N/2+1]=N/2+1;
	for (int i=1; i<=N; i++) printf("%d%c", A[i], i==N?'\n':' ');
    } else {
	puts("-1");
    }
    return 0;
}