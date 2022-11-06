#include <stdio.h>
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

typedef long long i64;

const int MAX_N = 1000000 + 5;
const int P = 1000000007;

int N, fath[MAX_N], f[MAX_N], g[MAX_N], ans;
i64 sa[MAX_N];

i64 gcd(i64 a, i64 b) {
    while (b) {
        i64 t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main() {
    N = read_int();
    for (int i = 1; i <= N; i ++) {
        sa[i] = read_int();
    }
    for (int i = 2; i <= N; i ++) {
        fath[i] = read_int();
    }
    for (int i = N; i >= 1; i --) {
        sa[fath[i]] += sa[i];
    }
    for (int i = 1; i <= N; i ++) {
        i64 t = sa[1] / gcd(sa[1], sa[i]);
        if (t <= N) {
            f[t] ++;
        }
    }
    for (int i = N; i >= 1; i --) {
        for (int j = i + i; j <= N; j += i) {
            f[j] += f[i];
        }
    }
    g[1] = 1;
    for (int i = 1; i <= N; i ++) {
        if (f[i] == i) {
            ans += g[i];
            ans -= ans >= P ? P : 0;
            for (int j = i + i; j <= N; j += i) {
                g[j] += g[i];
                g[j] -= g[j] >= P ? P : 0;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}