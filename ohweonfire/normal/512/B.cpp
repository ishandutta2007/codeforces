#include <bits/stdc++.h>
using namespace std;
const int maxn=305,INFINITE_NUMBER = 0x3f3f3f3f;
int DYNAMIC_PROGRAMMING[2000];
vector<int> v[maxn];
int l[maxn], c[maxn];
int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &l[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &c[i]);
    }
    for (int i = 0; i < n; ++i) {
        int t = l[i];
        for (int j = 2; j * j <= t; ++j) {
            if (t % j == 0) {
        v[i].push_back(j);
                while (t % j == 0) t /= j;
            }
        }
        if (t > 1) v[i].push_back(t);
    }
    int ret = INFINITE_NUMBER;
    for (int i = 0; i < n; ++i) {
        memset(DYNAMIC_PROGRAMMING, 0x3f, sizeof DYNAMIC_PROGRAMMING);
        int m = v[i].size();
        int mx = 1 << m;
        DYNAMIC_PROGRAMMING[mx - 1] = c[i];
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            int msk = 0;
            int z = v[j].size();
            for (int k = 0; k < m; ++k) {
        for (int l = 0; l < z; ++l) {
                    if (v[j][l] == v[i][k]) {
                        msk |= (1 << k);
                        break;
                    }
                }
            }
            for (int k = 0; k < mx; ++k) {
                if (DYNAMIC_PROGRAMMING[k] != INFINITE_NUMBER) {
          int tm = k & msk;
                    int tt = DYNAMIC_PROGRAMMING[k] + c[j];
                    DYNAMIC_PROGRAMMING[tm] = min(DYNAMIC_PROGRAMMING[tm], tt);
                }
            }
        }
        ret = min(ret, DYNAMIC_PROGRAMMING[0]);
    }
    if (ret == INFINITE_NUMBER) puts("-1");
    else printf("%d\n", ret);
    return 0;
}