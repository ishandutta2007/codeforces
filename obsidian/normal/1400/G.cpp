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
const int P = 998244353;

int pow(int x, int y) {
    int res = 1;
    while (y) {
        if (y & 1) res = (LL) res * x % P;
        x = (LL) x * x % P;
        y /= 2;
    }
    return res;
}

const int V = 300100;
const int N = 1 << 20;
int l[V], r[V];
int pt[V], fac[V], rf[V];
int u[30], v[30], K;

struct Node {
    int type, v, cnt;
}e[(V + N) * 2 + V];

void add(int type, int v, int cnt) {
    e[K].type = type;
    e[K].v = v;
    e[K].cnt = cnt;
    K++;
}

bool cmp(Node x, Node y) {
    if (x.v != y.v) return x.v < y.v;
    return x.type < y.type;
}

int cnt[50], n, m;

int main() {
    fac[0] = 1;
    for (int i = 1; i < V; ++i) fac[i] = (LL) fac[i - 1] * i % P;
    for (int i = 0; i < V; ++i) rf[i] = pow(fac[i],  P - 2);
    pt[0] = 1;
    for (int i = 1; i < V; ++i) pt[i] = pt[i - 1] * 2 % P;
    while (~scanf("%d%d", &n, &m)) {
        K = 0;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; ++i) scanf("%d%d", &l[i], &r[i]);
        for (int i = 0; i < m; ++i) scanf("%d%d", &u[i], &v[i]);
        for (int i = 1; i < (1 << m); ++i) {
            int xs = 1;
            int mi = 0, mx = n;
            set<int> st;
            for (int j = 0; j < m; ++j) {
                if (i & (1 << j)) {
                    xs *= -1;
                    mi = max(l[u[j]], mi);
                    mi = max(l[v[j]], mi);
                    mx = min(r[u[j]], mx);
                    mx = min(r[v[j]], mx);
                    st.insert(u[j]);
                    st.insert(v[j]);
                }
            }
            //printf("SUB %d %d %d %d %d\n", i, mi, mx, st.size(), xs);
            if (mi <= mx) {
                add(-1, mi, st.size() * xs);
                add(1, mx, st.size() * xs);
            }
        }
        for (int i = 1; i <= n; ++i) {
            add(-1, l[i], 0);
            add(1, r[i], 0);
        }
        for (int i = 1; i <= n;++i) {
            add(0, i, 0);
        }
        sort(e, e + K, cmp);
        int ans = 0;
        int cur = 0;
        for (int i = 0; i < K; ++i) {
            Node x = e[i];
            //printf("E %d %d %d\n", x.type, x.v, x.cnt);
            if (x.type == 0) {
                //printf("Cur %d\n", cur);
                //for (int j = 1; j <= 2 * m; ++j) printf("%d ", cnt[j]); puts("CNT");
                if (cur >= x.v) {
                    ans = (ans + (LL) fac[cur] * rf[x.v] % P * rf[cur - x.v]) % P;
                    for (int j = 1; j <= 2 * m && j <= x.v; ++j) {
                        ans = (ans + (LL) fac[cur - j] * rf[x.v - j] % P * rf[cur - x.v] % P * cnt[j] % P + P) % P;
                    }
                }
            } else if (x.type == -1) {
                if (x.cnt == 0) ++cur;
                else if (x.cnt > 0) ++cnt[x.cnt];
                else --cnt[-x.cnt];
            } else {
                if (x.cnt == 0) --cur;
                else if (x.cnt > 0) --cnt[x.cnt];
                else ++cnt[-x.cnt];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

/*
3 0
1 1
2 3
1 3

3 1
1 1
2 3
1 3
2 3
*/