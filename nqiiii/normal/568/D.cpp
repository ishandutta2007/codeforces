#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include <bits/stdc++.h>
using namespace std;
const int maxN = 100000;
const double eps = 1e-7;
int n, k;
int a[maxN + 10], b[maxN + 10], c[maxN + 10];
int ans[maxN + 10][2], ansCnt;
vector<int> o;

pair<double, double> GetCrs(int p, int q) {
    double x =  1.0 * (1ll * b[p] * c[q] - 1ll * b[q] * c[p]) / (1ll * a[p] * b[q] - 1ll * a[q] * b[p]);
    double y;
    if (b[p]) y = (-c[p] - a[p] * x) / b[p];
    else y = (-c[q] - a[q] * x) / b[q];
    return make_pair(x, y);
}

void Dfs(vector<int> o, int d) {
    if (o.empty()) {
        printf("YES\n");
        printf("%d\n", ansCnt);
        for (int i = 1; i <= ansCnt; ++i)
            printf("%d %d\n", ans[i][0], ans[i][1]);
        exit(0);
    }
    if (!d) return;
    if (o.size() == 1) {
        ans[++ansCnt][0] = o[0];
        ans[ansCnt][1] = -1;
        o.clear();
        Dfs(o, d - 1);
    } else {
        if (o.size() > 30 * d) {
            for (int test = 1; test <= 100; ++test) {
                int i = rand() % o.size(), j = rand() % o.size();
                int p = o[i], q = o[j];
                if (i == j || 1ll * a[p] * b[q] == 1ll * a[q] * b[p]) continue;
                pair<double, double> pnt = GetCrs(p, q);
                ans[++ansCnt][0] = p; ans[ansCnt][1] = q;
                vector<int> now;
                for (int k = 0; k < o.size(); ++k)
                    if (k != i && k != j) {
                        int t = o[k];
                        if (1ll * a[p] * b[t] == 1ll * b[p] * a[t]) now.push_back(t); else {
                            pair<double, double> r = GetCrs(p, t);
                            if (fabs(pnt.first - r.first) > eps || fabs(pnt.second - r.second) > eps) now.push_back(t);
                        }
                    }
                if (o.size() - now.size() >= d + 1) {
                    Dfs(now, d - 1); --ansCnt; break;
                }
                --ansCnt;
            }
            return;
        }
        for (int i = 0; i < o.size() && i <= d; ++i)
            for (int j = i + 1; j < o.size() && j <= d; ++j) {
                int p = o[i], q = o[j];
                if (1ll * a[p] * b[q] == 1ll * a[q] * b[p]) continue;
                pair<double, double> pnt = GetCrs(p, q);
                ans[++ansCnt][0] = p; ans[ansCnt][1] = q;
                vector<int> now;
                for (int k = 0; k < o.size(); ++k)
                    if (k != i && k != j) {
                        int t = o[k];
                        if (1ll * a[p] * b[t] == 1ll * b[p] * a[t]) now.push_back(t); else {
                            pair<double, double> r = GetCrs(p, t);
                            if (fabs(pnt.first - r.first) > eps || fabs(pnt.second - r.second) > eps) now.push_back(t);
                        }
                    }
                Dfs(now, d - 1);
                --ansCnt;
            }
    }
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
        o.push_back(i);
    }
    Dfs(o, k);
    printf("NO");
}