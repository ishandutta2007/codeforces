#include <stdio.h>
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(X) (X).begin(), (X).end()
#define lep(i, j, k) for (int i = (j); i <= (k); i++)
#define rep(i, j, k) for (int i = (j); i >= (k); i--)
#define Lep(i, j, k) for (int i = (j); i < (k); i++)
#define Rep(i, j, k) for (int i = (j); i > (k); i--)

using namespace std;

using ll = long long;
using ull = unsigned long long;
template <class T> using V = vector<T>;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;

template <typename T>
void ckmin(T &A, T B) {A = A < B ? A : B;}
template <typename T>
void ckmax(T &A, T B) {A = A > B ? A : B;}

inline void read(int &x) {scanf("%d", &x);}
inline void print(int x) {printf("%d", x);}
inline void print(int x, char c) {printf("%d%c", x, c);}
inline void read(long long &x) {scanf("%lld", &x);}
inline void print(long long x) {printf("%lld", x);}
inline void print(long long x, char c) {printf("%lld%c", x, c);}

const int N = 2e5 + 10;

int n, m, a[N], b[N], fa[N], ct[N], l[N], r[N];
ll sa[N], sb[N];
vector<int> G[N], use;

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void con(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    fa[x] = y;
}

void solve() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), sa[i] = sa[i - 1] + a[i];
    for (int i = 1; i <= n; i++)
        scanf("%d", &b[i]), sb[i] = sb[i - 1] + b[i];
    for (int i = 1; i <= m; i++)
        scanf("%d%d", &l[i], &r[i]);
    if (sa[n] != sb[n]) return puts("NO"), void();
    for (int i = 0; i <= n + 1; i++) fa[i] = i;
    int lst = 0;
    fa[0] = 1;
    for (int i = 1; i <= n; i++)
        if (sa[i] - sa[lst] == sb[i] - sb[lst]) {
            con(i, i + 1);
            lst = i;
        }
    for (int i = 1; i <= m; i++) ct[i] = 2;
    use.clear();
    for (int i = 0; i <= n + 1; i++)
        G[i].clear();
    for (int i = 1; i <= m; i++) {
        if (find(l[i] - 1) != l[i] - 1) ct[i]--;
        else G[l[i] - 1].push_back(i);
        if (find(r[i]) != r[i]) ct[i]--;
        else G[r[i]].push_back(i);
        if (ct[i] == 0) use.push_back(i);
    }
    while (find(0) != n + 1 && use.size()) {
        int id = use.back(); use.pop_back();
        int tl = l[id], tr = r[id];
        tl = find(tl);
        while (tl < tr + 1) {
            for (int x : G[tl]) {
                ct[x]--;
                if (!ct[x]) use.push_back(x);
            }
            con(tl, tl + 1);
            tl = find(tl);
        }
    }
    puts(find(0) == n + 1 ? "YES" : "NO");
}

int main() {
    int T;
    for (scanf("%d", &T); T; T--) solve();
    return 0;
}