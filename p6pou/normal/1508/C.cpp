#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 200000 + 5;

int N, M, X;
long long M_, ans0, ans;
struct Edge {
    int x, y, z, f;
    bool operator < (const Edge &e) const {
        return z < e.z;
    }
} e[MAX_N];
vector<int> ve[MAX_N];

int fath[MAX_N], nxt[MAX_N];
int get_fath(int i) {
    return fath[i] == i ? i : fath[i] = get_fath(fath[i]);
}
int get_nxt(int i) {
    return nxt[i] == i ? i : nxt[i] = get_nxt(nxt[i]);
}
void merge_section(int i, int kl, int kr) {
    // printf("merge: i=%d, kl=%d, kr=%d\n", i, kl, kr);
    for (int k = kl; k <= kr; k ++) {
        // printf("    k=%d\n", k);
        k = get_nxt(k);
        if (k <= kr) {
            fath[get_fath(k)] = get_fath(i);
            nxt[k] = kr;
        }
    }
}

int main() {
    scanf("%d%d", &N, &M);
    M_ = (N * (N - 1ll) >> 1) - M;
    for (int i = 1; i <= M; i ++) {
        scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].z);
        ve[e[i].x].push_back(e[i].y);
        ve[e[i].y].push_back(e[i].x);
        X ^= e[i].z;
    }
    sort(e + 1, e + 1 + M);
    for (int i = 1; i <= N; i ++) {
        fath[i] = nxt[i] = i;
        if (ve[i].size()) {
            sort(ve[i].begin(), ve[i].end());
        }
    }
    for (int i = 1; i <= N; i ++) {
        if (ve[i].size() == 0) {
            merge_section(i, 1, N);
            break;
        } else {
            merge_section(i, 1, ve[i].front() - 1);
            for (int j = 0; j + 1 < (int) ve[i].size(); j ++) {
                merge_section(i, ve[i][j] + 1, ve[i][j + 1] - 1);
            }
            merge_section(i, ve[i].back() + 1, N);
        }
    }
    int tmp = 0;
    for (int i = 1; i <= N; i ++) {
        int fa = get_fath(i);
        tmp += fa != i;
        // printf("i=%d, fa=%d\n", i, fa);
    }
    // printf("tmp=%d, M_=%lld\n", tmp, M_);
    if (tmp < M_) {
        for (int i = 1; i <= M; i ++) {
            int x = get_fath(e[i].x);
            int y = get_fath(e[i].y);
            if (x != y) {
                ans += e[i].z;
                fath[x] = y;
            }
        }
    } else {
        ans0 = X;
        for (int i = 1; i <= M; i ++) {
            int x = get_fath(e[i].x);
            int y = get_fath(e[i].y);
            if (x != y) {
                ans0 += e[i].z;
                e[i].f = 1;
                fath[x] = y;
            }
        }
        ans = ans0;
        for (int i = 1; i <= N; i ++) {
            fath[i] = i;
        }
        for (int i = 1; i <= M; i ++) {
            if (e[i].f) {
                fath[get_fath(e[i].x)] = get_fath(e[i].y);
            }
        }
        for (int i = 1; i <= M; i ++) {
            if (!e[i].f) {
                int x = get_fath(e[i].x);
                int y = get_fath(e[i].y);
                if (x != y) {
                    ans = min(ans, ans0 - X + e[i].z);
                }
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}