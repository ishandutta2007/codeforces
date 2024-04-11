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
const int V = 500100;
const int N = 61;
LL a[V];
int cnt[N];
int _, n;

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
        for (int i = 0; i < N; ++i) cnt[i] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < N; ++j) {
                if (a[i] & (1LL << j)) cnt[j]++;
            }
        }
        LL ans = 0;
        for (int i = 0; i < n; ++i) {
            LL x = 0, y = 0;
            for(int j = 0; j < N; ++j) {
                if (a[i] & (1LL << j)) {
                    x = (x + (1LL << j) % P * cnt[j]) % P;
                    y = (y + (1LL << j) % P * n) % P;
                } else {
                    y = (y + (1LL << j) % P * cnt[j]) % P;
                }
            }
            ans = (ans + x * y) % P;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}

/*
8
2
1 7
3
1 2 4
4
5 5 5 5
5
6 2 2 1 0
1
0
1
1
6
1 12 123 1234 12345 123456
5
536870912 536870911 1152921504606846975 1152921504606846974 1152921504606846973
*/