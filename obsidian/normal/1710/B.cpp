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
const int oo = 1e9;
const LL inf = (LL) oo * oo;
const int P = 1000000007;
const int V = 200100;
struct Node{int x, d;}e[3 * V];
bool cmp(Node x, Node y) {
    return x.x < y.x;
}
int _, n, K, x[V], p[V], en;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d", &n, &K);
        en = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &x[i], &p[i]);
            e[en++] = {x[i] - p[i], 1};
            e[en++] = {x[i], -2};
            e[en++] = {x[i] + p[i], 1};
        }
        sort(e, e + en, cmp);
        LL cur = 0;
        int slope = 0;
        LL mx_minus = -inf, mx_plus = -inf;
        for (int i = 0; i < en; ++i) {
            if (i != 0 && e[i].x != e[i - 1].x) cur += (LL) slope * (e[i].x - e[i - 1].x);
            slope += e[i].d;
            //printf("%d %d %lld\n", e[i].x, slope, cur);
            if (i == en - 1 || e[i].x != e[i + 1].x) {
                if (cur > K) {
                    //printf("MP %lld %lld\n", cur - K - e[i].x, cur - K + e[i].x);
                    mx_minus = max(mx_minus, cur - K - e[i].x);
                    mx_plus = max(mx_plus, cur - K + e[i].x);
                }
            }
        }
       // printf("M & P %lld %lld\n", mx_minus, mx_plus);
        for (int i = 0; i < n; ++i) {
            if (p[i] - x[i] >= mx_minus && p[i] + x[i] >= mx_plus) putchar('1');
            else putchar('0');
        }
        puts("");
    }
    return 0;
}

/*
4
3 6
1 5
5 5
3 4
2 3
1 3
5 2
2 5
1 6
10 6
6 12
4 5
1 6
12 5
5 5
9 7
8 3
*/