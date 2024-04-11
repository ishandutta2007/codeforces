#include <bits/stdc++.h>

using namespace std;

int const N = 1234567;

int s[N], t[N];

int main() {
    int n = 0;
    int c = getchar();
    while (c <= 32) c = getchar();
    while (c > 32) {
        s[n++] = c;
        c = getchar();
    }
    int m = 0;
    while (c <= 32) c = getchar();
    while (c > 32) {
        t[m++] = c;
        c = getchar();
    }
    assert(n == m);
    int dif = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) dif++;
    }
    if (dif % 2 != 0) {
        puts("impossible");
        return 0;
    }
    dif /= 2;
    for (int i = 0; dif > 0 && i < n; i++) {
        if (s[i] != t[i]) {
            --dif;
            s[i] = t[i];
        }
    }
    for (int i = 0; i < n; i++) putchar(s[i]);
    puts("");
}