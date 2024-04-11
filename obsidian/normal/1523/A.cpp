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
char s[V];
int ans[V], n, m, _;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d", &n, &m);
        scanf("%s", s);
        for (int i = 0; i < n; ++i) ans[i] = s[i] - '0';
        for (int i = 0; i < n; i++) {
            int L = m + 1, R = m + 1;
            for (int j = i - 1; j >= 0; --j) {
                if (s[j] == '1') {L = i - j;break;}
            }
            for (int j = i + 1; j < n; ++j) {
                if (s[j] == '1') {R = j - i;break;}
            }
            if (L != R && min(L, R) <= m) ans[i] = 1;
        }
        for (int i = 0; i < n; ++i) printf("%d", ans[i]); puts("");
    }
    return 0;
}

/*
4
11 3
01000000001
10 2
0110100101
5 2
10101
3 100
000
*/