#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>

#define x first
#define y second
#define MP std::make_pair
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define DEBUG(...) fprintf(stderr, __VA_ARGS__)
#ifdef __linux__
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif

using std::pair;
using std::vector;
using std::string;

typedef long long LL;
typedef pair<int, int> Pii;

const int oo = 0x3f3f3f3f;

template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return b < a ? a = b, true : false; }
string procStatus()
{
    std::ifstream t("/proc/self/status");
    return string(std::istreambuf_iterator<char>(t), std::istreambuf_iterator<char>());
}
template<typename T> T read(T &x)
{
    int f = 1;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar())
        f = (ch == '-' ? -1 : 1);
    for (x = 0; isdigit(ch); ch = getchar())
        x = 10 * x + ch - '0';
    return x *= f;
}
template<typename T> void write(T x)
{
    if (x == 0) {
        putchar('0');
        return;
    }
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    static char s[20];
    int top = 0;
    for (; x; x /= 10)
        s[++top] = x % 10 + '0';
    while (top)
        putchar(s[top--]);
}
// EOT

const int MAXN = 2e5 + 5;

struct Edge {
    int v, next;
    Edge() { }
    Edge(int v_, int next_): v(v_), next(next_) { }
};

int N;
int tote, head[MAXN];
Edge edge[MAXN * 2 + 5];

inline void addEdge(int u, int v)
{
    edge[++tote] = Edge(v, head[u]);
    head[u] = tote;
}

void input()
{
    read(N);
    for (int i = 1; i < N; ++i) {
        int u, v;
        read(u); read(v);
        addEdge(u, v);
        addEdge(v, u);
    }
}

namespace Centroid
{

int size[MAXN];
int centroid;
int minmaxsubtree;

void dfs(int u, int f)
{
    int maxsonsize = 0;
    size[u] = 1;
    for (int i = head[u]; i; i = edge[i].next) {
        int v = edge[i].v;
        if (v == f)
            continue;
        dfs(v, u);
        size[u] += size[v];
        chkmax(maxsonsize, size[v]);
    }
    chkmax(maxsonsize, N - size[u]);
    if (chkmin(minmaxsubtree, maxsonsize))
        centroid = u;
}

int get()
{
    minmaxsubtree = +oo;
    dfs(1, 0);
    return centroid;
}

}

vector<std::tuple<int, int, int> > ans;
int S, T, L;

void dfs(int u, int fa)
{
    if (fa != S) {
        if (T != u) ans.push_back({S, T, u});
        if (fa != L) ans.push_back({u, fa, L});
        T = u;
    }
    for (int i = head[u]; i; i = edge[i].next) {
        int v = edge[i].v;
        if (v == fa)
            continue;
        dfs(v, u);
    }
}

void calc(int u, int fa)
{
    S = u;
    for (int i = head[u]; i; i = edge[i].next) {
        int v = edge[i].v;
        if (v == fa)
            continue;
        T = L = v;
        dfs(v, u);
        if (T != L) ans.push_back({S, T, L});
    }
}

void solve()
{
    int rt = Centroid::get();
    Centroid::dfs(rt, 0);
    for (int i = head[rt]; i; i = edge[i].next) {
        int v = edge[i].v;
        if (Centroid::size[v] * 2 == N) {
            calc(rt, v);
            calc(v, rt);
            goto OUTPUT;
        }
    }
    calc(rt, 0);

  OUTPUT:
    printf("%d\n", SZ(ans));
    for (auto &x : ans) {
        printf("%d %d %d\n", std::get<0>(x), std::get<1>(x), std::get<2>(x));
    }
}

int main()
{
#ifdef __DEBUG
    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);
#endif

    input();
    solve();

    return 0;
}