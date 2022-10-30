#include <bits/stdc++.h>
using namespace std;

int n, a, b;
long long t;
char s[1000005];
long long moveright[1000005];
long long moveleft[1000005];
long long moverightplus[1000005];

int watchtime(int i) {
    if (s[i] == 'w') {
        return b + 1;
    } else {
        return 1;
    }
}


int main() {
    scanf("%d %d %d %lld", &n, &a, &b, &t);
    scanf("%s", s);
    for (int i = n - 1; i >= 1; i--) {
        moveleft[i] = moveleft[i + 1] + a + watchtime(i);
    }
    for (int i = 1; i < n; i++) {
        moveright[i] = moveright[i - 1] + a + watchtime(i);
    }
    for (int i = 1; i < n; i++) {
        moverightplus[i] = moveright[i] + i * a;
    }
    if (watchtime(0) > t) {
        printf("0\n");
        return 0;
    }
    long long result = 0;
    for (int i = n; i >= 1; i--) {
        long long tnow = watchtime(0) + moveleft[i] + (n - i) * a;
        long long rest = t - tnow;
        long long numl = n - i;
        if (rest >= 0) {
            long long pos = upper_bound(moveright, moveright + n, rest) - moveright;
            long long numr = pos - 1;
            if (numl + numr + 1 > n) {
                result = n;
            } else {
                result = max(result, numl + numr + 1);
            }
        }
    }
    for (int i = n; i >= 1; i--) {
        long long tnow = watchtime(0) + moveleft[i];
        long long rest = t - tnow;
        long long numl = n - i;
        if (rest >= 0) {
            long long pos = upper_bound(moverightplus, moverightplus + n, rest) - moverightplus;
            long long numr = pos - 1;
            if (numl + numr + 1 > n) {
                result = n;
            } else {
                result = max(result, numl + numr + 1);
            }
        }
    }
    printf("%lld\n", result);

}