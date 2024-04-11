#pragma gcc optmize("Ofast")
#include <bits/stdc++.h>
int n, sqrtn, oth, cnt, term;
int main() {
    scanf("%d", &n);
    sqrtn = ceil(sqrt(n));
    while(cnt < n) {
        ++term;
        for(int i = 1; i <= sqrtn && cnt < n; ++i) {
            if(n - term * sqrtn + i <= 0) continue;
            printf("%d ", n - term * sqrtn + i);
            ++cnt;
        }
    }
    return 0;
}