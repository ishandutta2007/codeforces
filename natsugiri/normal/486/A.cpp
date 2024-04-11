#include<cstdio>

using namespace std;

typedef long long LL;


LL N;

int main() {
    scanf("%lld", &N);
    if (N % 2) printf("%lld\n", -N + N/2);
    else  printf("%lld\n", N/2);

    return 0;
}