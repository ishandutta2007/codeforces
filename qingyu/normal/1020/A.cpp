#pragma GCC optmize("Ofast")
#include <bits/stdc++.h>

int n, h, a, b, k;

int main(void) {
    scanf("%d%d%d%d%d", &n, &h, &a, &b, &k);
    //printf("%d %d %d %d %d \n", n, h, a, b, k);
    while (k--) {
        int fa, fb, ta, tb;
        scanf("%d%d%d%d", &ta, &fa, &tb, &fb);
        if((fa >= a && fa <= b) || (fb >= a && fb <= b) || ta == tb) printf("%d\n", abs(ta - tb) + abs(fa - fb));
        else {
            //printf("%d %d %d %d %d %d\n", abs(fa - a), abs(ta - tb), abs(a - fb), abs(fa - b), abs(ta - tb), abs(b - fb));
            int ans = std::min(abs(fa - a) + abs(ta - tb) + abs(a - fb), abs(fa - b) + abs(ta - tb) + abs(b - fb));
            printf("%d\n", ans);
        }
    }
}