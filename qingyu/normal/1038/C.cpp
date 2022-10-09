#include <bits/stdc++.h>

long long A[100005], B[100005];

inline int nc() {
    static char buf[1000000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}

inline int read() {
    int res = 0, ch = nc();
    while (!isdigit(ch)) ch = nc();
    while (isdigit(ch)) res = res * 10 + ch - 48, ch = nc();
    return res;
}

int main() {
    int n = read();
    for (int i = 0; i < n; ++i) A[i] = read();
    for (int i = 0; i < n; ++i) B[i] = read();
    std::sort(A, A + n, std::greater<long long>());
    std::sort(B, B + n, std::greater<long long>());
    long long pL = 0, pR = 0, score = 0;
    while (pL < n || pR < n) {
        if (A[pL] > B[pR]) {
            score += A[pL];
            ++pL;
        }
        else ++pR;
        if (A[pL] > B[pR]) ++pL;
        else {
            score -= B[pR];
            ++pR;
        }
    }
    printf("%lld", score);
    return 0;
}
//By Qingyu