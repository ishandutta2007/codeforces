#include <bits/stdc++.h>
using namespace std;

int N, K, odd, even;

int main() {
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        if (x % 2 == 0) even++;
        else odd++;
    }
    if (N == K) {
        if (odd % 2 == 1) printf("Stannis\n");
        else printf("Daenerys\n");
        return 0;
    }
    if ((N - K) % 2 == 0) {
        if ((N-K)/2 >= even && (N-K-even) % 2 == (odd % 2 + 1) % 2) printf("Stannis\n");
        else printf("Daenerys\n");
    }
    else {
        if ((N-K)/2 >= odd) printf("Daenerys\n");
        else if ((N-K)/2 >= even && (N-K-even) % 2 == odd % 2) printf("Daenerys\n");
        else printf("Stannis\n");
    }
}