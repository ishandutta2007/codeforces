#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
    #define dbg(...)
#endif

#define st first
#define nd second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define len(x) ((int)(x).size())
#define low(x) ((x) & (-(x)))
#define forn(i, n) for (int i = 0; i < n; ++i)

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef string str;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<typename... Args>
void _dbg(const char* s, Args&&... args) {
    cerr << "[ " <<  s << " = ";
    ((cerr << std::forward<Args>(args) << ", "), ...);
    cerr << "]\n";
}

template<typename... Args>
void print(Args&&... args) {
    ((cout << std::forward<Args>(args) << " "), ...);
    cout << "\n";
}

template<typename T, typename Alloc>
std::ostream& operator<<(std::ostream& out, const std::vector<T, Alloc>& v) {
    bool isfirst = true;
    for (const auto& x : v) {
        if (!isfirst)
            out << ' ';
        else
            isfirst = false;
        out << x;
    }
    return out;
}

template<typename T, typename Alloc>
std::ostream& operator<<(std::ostream& out, const std::set<T, Alloc>& v) {
    bool isfirst = true;
    for (const auto& x : v) {
        if (!isfirst)
            out << ' ';
        else
            isfirst = false;
        out << x;
    }
    return out;
}

const int D = 10;
const int N = 2 * ((1 << D) + 7);
char buf[D + 7];
int a[N], match[N];
bool vis[N];
vi g[N];

bool cmp(int a, int b) {
    return __builtin_popcount(a) > __builtin_popcount(b);
}

bool dfs(int v) {
    for (int s : g[v])
        if (!vis[s]) {
            vis[s] = true;
            int ms = match[s];
            if (ms == -1 || dfs(ms)) {
                match[s] = v;
                return true;
            }
        }
    return false;
}

void solve() {
    int d, n;
    scanf("%d%d", &d, &n);

    forn (i, n) {
        scanf("%s", buf);
        forn (j, d)
            if (buf[j] == '1')
                a[i] |= 1 << j;
    }

    sort(a, a + n, cmp);
    forn (i, n)
        forn (j, i)
            if ((a[i] & a[j]) == a[i])
                g[i].pb(j);

    int res = 0;
    vi vs; // koce cieek
    fill(match, match + n, -1);

    forn (i, n) {
        fill(vis, vis + n, false);
        // i jest wolny
        if (!dfs(i)) {
            res += __builtin_popcount(a[i]) + 1;
            vs.pb(i);
        }
    }

    printf("%d\n", res - 1);
    
    bool first = true;
    vi ts;
    for (int v : vs) {
        if (!first)
            printf("R ");
        else
            first = false;

        int cur = v;
        do {
            ts.push_back(cur);
            cur = match[cur];
        } while (cur != -1);

        reverse(all(ts));

        int last = 0;
        for (int v : ts) {
            int diff = last ^ a[v];
            forn (i, d)
                if (diff & 1 << i)
                    printf("%d ", i);
            last = a[v];
        }

        ts.clear();
    }
    puts("");
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) {
        solve();
    }

    return 0;
}