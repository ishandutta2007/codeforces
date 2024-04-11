#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 500000 + 5;

int N, M, K, E, BAD;
int c[MAX_N];
int fath[MAX_N], dis[MAX_N], siz[MAX_N];
int ex[MAX_N], ey[MAX_N];
int block_bad[MAX_N];
long long ans;
map<pair<int,int>, vector<pair<int,int>>> ee;

int get_fath(int u) {
    if (fath[u] != u) {
        int fa = fath[u];
        fath[u] = get_fath(fa);
        dis[u] ^= dis[fa];
    }
    return fath[u];
}
void get_fath_2(int &u, int &d) {
    for (d = 0; u != fath[u]; d ^= dis[u], u = fath[u]);
}

int main() {
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 1; i <= N; i ++) {
        scanf("%d", &c[i]);
        fath[i] = i, dis[i] = 0;
    }
    for (int i = 1; i <= M; i ++) {
        scanf("%d%d", &ex[i], &ey[i]);
        if (c[ex[i]] == c[ey[i]]) {
            int x = get_fath(ex[i]);
            int y = get_fath(ey[i]);
            if (x != y) {
                fath[x] = y;
                dis[x] = dis[ex[i]] ^ dis[ey[i]] ^ 1;
            } else if (dis[ex[i]] ^ dis[ey[i]] ^ 1) {
                block_bad[c[x]] = 1;
            }
        }
    }
    for (int i = 1; i <= K; i ++) {
        BAD += block_bad[i];
    }
    for (int i = 1; i <= M; i ++) {
        int a = c[ex[i]], b = c[ey[i]];
        if (a != b && !block_bad[a] && !block_bad[b]) {
            if (a > b) swap(a, b), swap(ex[i], ey[i]);
            if (!ee.count(make_pair(a, b))) {
                ee[make_pair(a, b)] = vector<pair<int,int>>();
            }
            ee[make_pair(a, b)].push_back(make_pair(ex[i], ey[i]));
        }
    }
    for (int i = 1; i <= N; i ++) {
        siz[get_fath(i)] ++;
    }
    ans = (K - BAD) * (K - BAD - 1ll) >> 1;
    for (auto it = ee.begin(); it != ee.end(); it ++) {
        int a = it->first.first;
        int b = it->first.second;
        stack<int> s;
        for (auto ei: it->second) {
            int x = ei.first, u = ei.first, dx;
            int y = ei.second, v = ei.second, dy;
            get_fath_2(u, dx);
            get_fath_2(v, dy);
            if (u != v) {
                if (siz[u] < siz[v]) swap(u, v), swap(x, y);
                fath[u] = v;
                siz[v] += siz[u];
                dis[u] = dx ^ dy ^ 1;
                s.push(u);
            } else if (dx ^ dy ^ 1) {
                ans --;
                break;
            }
        }
        for (; !s.empty(); s.pop()) {
            int u = s.top(), v = fath[u];
            siz[v] -= siz[u];
            dis[u] = 0;
            fath[u] = u;
        }
    }
    printf("%lld\n", ans);
    return 0;
}