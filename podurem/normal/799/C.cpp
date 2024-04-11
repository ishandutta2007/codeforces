#include <bits/stdc++.h>

#define err(...) //fprintf(stderr, __VA_ARGS__), fflush(stdout)
typedef long long ll;

using namespace std;

const int dd = (int)1e5 + 7;

int b[dd], p[dd];
char C[dd];
pair<int, int> K[2][dd];
vector<pair<int, int> > H[2];

int main() {
    int n, c, d;
    scanf("%d %d %d", &n, &c, &d);
    for (int i = 0; i < n; ++i) {
        char t;
        int b, p;
        scanf("\n %d %d %c", &b, &p, &t);
        if (t == 'C') H[0].push_back({ p, b });
        else H[1].push_back({ p, b });
    }
    sort(H[0].begin(), H[0].end());
    sort(H[1].begin(), H[1].end());

    if ((int)H[0].size()) K[0][0] = { H[0][0].second, 0 };
    for (int i = 1; i < (int)H[0].size(); ++i)
        if (H[0][i].second > K[0][i - 1].first)
            K[0][i] = { H[0][i].second, i };
        else K[0][i] = K[0][i - 1];

    if ((int)H[1].size()) K[1][0] = { H[1][0].second, 0 };
    for (int i = 1; i < (int)H[1].size(); ++i)
        if (H[1][i].second > K[1][i - 1].first)
            K[1][i] = { H[1][i].second, i };
        else K[1][i] = K[1][i - 1];

    int MC = 0, MD = 0;
    int ans = 0;
    for (auto i : H[0]) if (i.first <= c) MC = max(MC, i.second);
    for (auto i : H[1]) if (i.first <= d) MD = max(MD, i.second);
    if (MC && MD) ans = MC + MD;

    if ((int)H[0].size() > 1) {
        for (int i = 0; i < (int)H[0].size(); ++i) {
            if (H[0][i].first > c) break;
            int u = lower_bound(H[0].begin(), H[0].end(), make_pair( c - H[0][i].first, (int)1e9 )) - H[0].begin() - 1;
            if (u < 0) continue;
            auto Y = K[0][u];
            if (Y.second != i) ans = max(ans, H[0][i].second + Y.first);
        }
    }

    if ((int)H[1].size() > 1) {
        for (int i = 0; i < (int)H[1].size(); ++i) {
            if (H[1][i].first > d) break;
            int u = lower_bound(H[1].begin(), H[1].end(), make_pair( d - H[1][i].first, (int)1e9 )) - H[1].begin() - 1;
            if (u < 0) continue;
            auto Y = K[1][u];
            if (Y.second != i) ans = max(ans, H[1][i].second + Y.first);
        }
    }
    printf("%d\n", ans);
    return 0;
}