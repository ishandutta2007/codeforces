#include <bits/stdc++.h>
using namespace std;
const int maxN = 100000;
int n, q, c[maxN + 10], nowL, nowR;
bool isR;

void Add(int p, int v) {
    for (; p <= n; p += p & -p) c[p] += v;
}
int Query(int p) {
    int ans = 0;
    for(; p; p -= p & -p) ans += c[p];
    return ans;
}
int GetNum(int p) {
    return Query(p) - Query(p - 1);
}

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) Add(i, 1);
    nowL = 1; nowR = n;
    while (q--) {
        int op, x, y; scanf("%d%d", &op, &x);
        if (op == 1) {
            if (isR) x = nowR - nowL + 1 - x;
            if (x * 2 <= nowR - nowL + 1) {
                if (isR) isR = 0;
                for (int j = nowL; j < nowL + x; ++j)
                    Add(nowL * 2 + x * 2 - 1 - j, GetNum(j));
                nowL += x;
            } else {
                if (!isR) isR = 1;
                for (int j = nowL + x; j <= nowR; ++j) 
                    Add(nowL * 2 + x * 2 - 1 - j, GetNum(j));
                nowR = nowL + x - 1;
            }
        } else {
            scanf("%d", &y); ++x;
            if (isR) {
                x = nowR - nowL + 2 - x;
                y = nowR - nowL + 2 - y;
                swap(x, y);
            }
            printf("%d\n", Query(nowL + y - 1) - Query(nowL + x - 2));
        }
    }
}