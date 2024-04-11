#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 105;

char s[N];
int na, nb, nc;
int pa, pb, pc;
int ca, cb, cc;
LL r;

bool check (LL x) {
    LL tot = 0;
    tot += max(0LL, (x * ca - na) * pa);
    tot += max(0LL, (x * cb - nb) * pb);
    tot += max(0LL, (x * cc - nc) * pc);
    return tot <= r;
}

int main() {
    gets(s);
    scanf ("%d %d %d", &na, &nb, &nc);
    scanf ("%d %d %d", &pa, &pb, &pc);
    scanf ("%I64d", &r);
    
    for (int i=0; i<strlen(s); i++) {
        if (s[i] == 'B') ca++;
        if (s[i] == 'S') cb++;
        if (s[i] == 'C') cc++;
    }
    
    LL l = 0;
    LL r = 100000000000000LL;
    LL ans = 0;
    while (l <= r) {
        LL mid = l + r >> 1;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    
    printf ("%I64d\n", ans);
    return 0;
}