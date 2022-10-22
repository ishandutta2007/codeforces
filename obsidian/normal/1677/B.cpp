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
const int V = 1000100;
char s[V];
int _, n, m;
int row[V], has[V], sum[V];

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d", &n, &m);
        scanf("%s", s);
        int col = 0;
        for (int i = 0; i < n* m; ++i) row[i] = has[i] = sum[i] = 0;
        for (int i = 0; i < n * m; ++i) {
            int v = s[i] - '0';
            if (i == 0) sum[i] = v;
            else sum[i] = sum[i - 1] + v;
            int r = sum[i];
            if (i >= m) r -= sum[i - m];
            if (r > 0) row[i % m]++;
            if (v == 1) {
                if (has[i % m] == 0) {
                    ++col;
                    has[i % m] = 1;
                }
            }
            printf("%d ", col + row[i % m]);
        }puts("");
    }
    return 0;
}

/*
3
2 2
1100
4 2
11001101
2 4
11001101
*/