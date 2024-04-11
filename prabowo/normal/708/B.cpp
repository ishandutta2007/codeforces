#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

typedef long long LL;
int a, b, c, d;

LL C2[N];

int main() {
    scanf ("%d %d %d %d", &a, &b, &c, &d);
    for (int i=0; i<N; i++) C2[i] = 1LL * i * (i-1) >> 1;
    
    int nol = lower_bound(C2, C2 + N, (LL) a) - C2;
    int one = lower_bound(C2, C2 + N, (LL) d) - C2;

    if (nol == 0 && one == 0) {
        if (b == 0 && c == 0) return 0 * printf("0\n");
        if (b == 1 && c == 0) return 0 * printf ("01\n");
        if (c == 1 && b == 0) return 0 * printf ("10\n");        
        return 0 * printf ("Impossible\n");
    } else if (nol == 0) {
        if (b + c == one) {
            for (int i=0; i<c; i++) printf ("1");
            printf ("0");
            for (int i=0; i<b; i++) printf ("1");
            return 0;
        }
    } else if (one == 0) {
        if (b + c == nol) {
            for (int i=0; i<b; i++) printf ("0");
            printf ("1");
            for (int i=0; i<c; i++) printf ("0");
            return 0;
        }
    }
    
    if (C2[nol] != a) return 0 * printf ("Impossible\n");
    if (C2[one] != d) return 0 * printf ("Impossible\n");
    
    if (1LL * nol * one != b + c) return 0 * printf ("Impossible\n");

    if (nol == 0 && one == 0) return 0 * printf ( "Impossible\n");
    if (nol == 0) {
        for (int i=0; i<one; i++) printf ("1");
        return 0;
    }
    if (one == 0) {
        for (int i=0; i<nol; i++) printf ("0");
        return 0;
    }
    
    int cnt = 0;
    for (int i=0; i<c/nol; i++) printf ("1"), cnt++;
    for (int i=0; i<nol-c%nol; i++) printf ("0"), cnt++;
    if (one + nol > cnt) printf ("1"), cnt++;
    for (int i=0; i<c%nol; i++) printf ("0"), cnt++;
    for (int i=0; i<nol+one-cnt; i++) printf ("1");
    printf ("\n");
    
    return 0;
}