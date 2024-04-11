#include<bits/stdc++.h>
using namespace std;
#define MAXN 1179859

int p, q;
bool prime[MAXN];

bool palin(int x) {
    int tmp = x;
    int ret = 0;
    while (tmp) {
        ret *= 10;
        ret += tmp % 10;
        tmp /= 10;
    }

    return ret == x;
}

int main() {
    for (int i=2; i<MAXN; i++) prime[i] = 1;
    for (int i=2; i*i<=MAXN; i++) if (prime[i]) for (int j=2*i; j<=MAXN; j+=i) prime[j] = 0;

    scanf("%d %d", &p, &q);

    int ans, pi, rub;
    ans = pi = rub = 0;
    for (int i=1; i<MAXN; i++) {
        pi += prime[i];
        rub += palin(i);
        if (pi <= rub * p / q) ans = i;
    }


    printf("%d\n", ans);
    return 0;
}