#include <bits/stdc++.h>
using namespace std;
const int maxn = 300000;
vector<int> divs[maxn + 10];
int mu[maxn + 10], pr[maxn + 10], pcnt;
int n, a[maxn + 10], f[maxn + 10], s[maxn + 10];
bool np[maxn + 10];
void pre() {
    mu[1] = 1;
    for (int i = 2; i <= maxn; ++i) {
        if (!np[i]) {
            pr[++pcnt] = i; mu[i] = -1;
        }
        for (int j = 1; j <= pcnt && i * pr[j] <= maxn; ++j) {
            np[i * pr[j]] = 1;
            if (i % pr[j] == 0) {
                mu[i * pr[j]] = 0; break;
            } else mu[i * pr[j]] = -mu[i];
        }
    }
    for (int i = 1; i <= maxn; ++i)
        for (int j = i; j <= maxn; j += i)
            divs[j].push_back(i);
}
int main() {
    pre(); memset(f, 0x3f, sizeof f);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int x; scanf("%d", &x);
        f[x] = 1;
        for (int j = 0; j < (int)divs[x].size(); ++j)
            ++a[divs[x][j]];
    }
    for (int i = maxn; i >= 1; --i) {
        for (int j = 0; j < (int)divs[i].size(); ++j) {
            int x = divs[i][j];
            for (int k = 0; k < (int)divs[x].size(); ++k) {
                int e = divs[x][k];
                s[e] += a[x] * mu[x / e];
            }
        }
        for (int j = 0; j < (int)divs[i].size(); ++j) {
            int x = divs[i][j];
            if (s[x]) f[x] = min(f[x], f[i] + 1);
        }
        for (int j = 0; j < (int)divs[i].size(); ++j) {
            int x = divs[i][j]; s[x] = 0;
        }
    }
    printf("%d", f[1] < 1e9 ? f[1] : -1);
}