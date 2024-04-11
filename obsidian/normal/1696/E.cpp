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
const int N = 400000;
const int V = 200100;
int Pow(int x, int y) {
    int res = 1;
    while (y) {
        if (y & 1) res = (LL) res * x % P;
        y /= 2; x = (LL) x * x % P;
    }
    return res;
}
int fac[V * 2], rev[V * 2];
int C(int n, int m) {
    return (LL) fac[n] * rev[m] % P * rev[n - m] % P;
}
int n, a[V];
int main() {
    fac[0] = 1;
    for (int i = 1; i <= N; ++i) fac[i] = (LL) fac[i - 1] * i % P;
    for (int i = 0; i <= N; ++i) rev[i] = Pow(fac[i], P - 2);
    while (~scanf("%d", &n)) {
        for (int i = 0; i <= n; ++i) scanf("%d", &a[i]);
        int ans = 0;
        for (int i = 0; i <= n; ++i) {
            if (a[i] == 0) continue;
            ans = (ans + C(i + a[i], i + 1)) % P;
        }
        printf("%d\n", ans);
    }
    return 0;
}

/*
2
2 2 0
10
12 11 8 8 6 6 6 5 3 2 1
*/