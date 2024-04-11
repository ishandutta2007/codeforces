#include <bits/stdc++.h>

using namespace std;

const int BUFFER_SIZE = 1 << 20;
char rb[BUFFER_SIZE], *rp = rb, *rt = rb;
inline char read_char() {
    return rp == rt ? (rt = rb + fread(rb, 1, BUFFER_SIZE, stdin), rp = rb, *rp ++) : *rp ++;
}
inline int read_int() {
    int x = 0;
    char ch = read_char(), flag = 0;
    while (ch != '-' && (ch < '0' || ch > '9')) {
        ch = read_char();
    }
    if (ch == '-') {
        flag = 1;
        ch = read_char();
    }
    for (x = 0; ch >= '0' && ch <= '9'; ch = read_char()) {
        x = x * 10 + (ch - '0');
    }
    return flag ? -x : x;
}

int main() {
    long long T, p, a, b, c;
    scanf("%lld", &T);
    while (T --) {
        scanf("%lld%lld%lld%lld", &p, &a, &b, &c);
        a = (p - 1 + a) / a * a;
        b = (p - 1 + b) / b * b;
        c = (p - 1 + c) / c * c;
        p = min(min(a, b), c) - p;
        printf("%lld\n", p);
    }
    return 0;
}