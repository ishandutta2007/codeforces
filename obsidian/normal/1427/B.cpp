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

const int V = 100100;
char s[V];
int _, n, m, K, a[V];

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d", &n, &K);
        scanf("%s", s);
        m = 0;
        int cur = 0;
        int fi = -1;
        for (int i = 0; i < n; ++i) if (s[i] == 'W') {fi = i; break;}
        for (int i = fi + 1; i < n; ++i) {
            if (s[i] == 'W') {
                if (cur > 0) a[m++] = cur;
                cur = 0;
            } else ++cur;
        }
        int la = cur;
        if (fi == -1) fi = n, la = 0;
        sort(a, a + m);
        int ans = 0, pre = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'W') ans += pre + 1, pre = 1;
            else pre = 0;
        }
        for (int i = 0; i < m; ++i) {
            if (a[i] <= K) {
                K -= a[i];
                ans += 2 * a[i] + 1;
            } else {
                ans += 2 * K;
                K = 0;
            }
        }
        if (fi == n) {
            if (K > 0) --K, ++ans;
            ans += min(fi - 1, K) *2;
        } else {
            ans += min(fi + la, K) *2;
        }
        printf("%d\n", ans);
    }
    return 0;
}

/*
8
5 2
WLWLL
6 5
LLLWWL
7 1
LWLWLWL
15 5
WWWLLLWWWLLLWWW
40 7
LLWLWLWWWLWLLWLWWWLWLLWLLWLLLLWLLWWWLWWL
1 0
L
1 1
L
6 1
WLLWLW
*/