#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;


LL tri(LL x) { return x * (x - 1) / 2; }

LL N, M;
int main() {
    scanf("%lld%lld", &N, &M);

    LL mi = 0, ma;
    mi += (N%M) * tri(N / M + 1);
    mi += (M-N%M) * tri(N / M);

    ma = tri(N-M+1);

    printf("%lld %lld\n", mi, ma);

    return 0;
}