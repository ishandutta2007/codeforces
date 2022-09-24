#include<cstdio>
#include<algorithm>
using namespace std;

int N, K, f, t, A;
int main() {
    scanf("%d%d", &N, &K);
    scanf("%d%d", &f, &t);
    A=f-max(0, t-K);
    for (;--N;) {
	scanf("%d%d", &f, &t);
	A=max(A, f-max(0, t-K));
    }
    printf("%d\n", A);

    return 0;
}