#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define fi first
#define se second
#define MP make_pair
const int P = 1000000007;

const int V = 1010;
LL A[V];
void S(int a, int b) {
    printf("1 %d %d\n", a, b);
    A[a] += A[b];
    printf("2 %d %d\n", a, b);
    A[b] -= A[a];
    printf("1 %d %d\n", a, b);
    A[a] += A[b];
}

void S(int a, int b, int c, int d) {
    S(a, b);
    S(b, c);
    S(c, d);
    S(a, d);
    S(b, d);
    S(c, d);
}

int _, n, a[V];
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%lld", &A[i]);
        int total = 0;
        if (n % 4 == 2) total += 6;
        int C = n / 4;
        total += C * 18;
        printf("%d\n", total);
        //printf("%d\n", C);
        for (int i = 0; i < C; i++) S(4 * i + 1, 4 * i + 2, 4 * i + 3, 4 * i + 4);
        if (C * 4 < n) S(C * 4 + 1, C * 4 + 2), S(C * 4 + 1, C * 4 + 2);
        //for (int i = 1; i <= n; ++i) printf("%lld ", A[i]); puts("");
    }
    return 0;
}

/*
2
4
1 1 1 1
4
4 3 1 2
*/