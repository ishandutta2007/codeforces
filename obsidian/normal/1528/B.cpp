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
const int P = 998244353;
const int V = 1000100;
int n, a[V], s[V], f[V];

int main() {
    while (~scanf("%d", &n)) {
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; j +=i) a[j]++;
        }
        f[0] = 0;s[0] = 0;
        for (int i = 1; i <= n; ++i) {
            f[i] = s[i - 1];
            f[i] = (f[i] + a[i]) % P;
            s[i] = (s[i - 1] + f[i]) % P;
            //printf("F %d %d %d\n", i, a[i], f[i]);
        }
        printf("%d\n", f[n]);
    }
    return 0;
}

/*
1
2
3
100
*/