#include <bits/stdc++.h>
using namespace std;

#define cerr cout
#define F first
#define S second
#define FOR(i,a,b) for (auto i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(auto i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;
string to_string(string s) { return '"' + s + '"';}
string to_string(char s) { return string(1, s);}
string to_string(const char* s) { return to_string((string) s);}
string to_string(bool b) { return (b ? "true" : "false");}
template <typename A> string to_string(A);
template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A> string to_string(A v) {bool f = 1; string r = "{"; for (const auto &x : v) {if (!f)r += ", "; f = 0; r += to_string(x);} return r + "}";}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {cerr << " " << to_string(H); debug_out(T...);}
#define pr(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

const int N = 1e6 + 10;
int n, pos;
vi g[N];
int cnt[N], ans[N], at[N], st[N], en[N], h[N], sub[N];
// void add(int u, int p, int x) {
//     cnt[h[u]] += x;
//     if (cnt[h[u]] > cnt[pos] or (cnt[h[u]] == cnt[pos] and h[u] < pos)) pos = h[u];
//     for (int v: g[u]) if (v != p) add(v, u, x);
// }

void dd(int u, int p) {
    sub[u] = 1;
    for (int v: g[u]) if (v != p) {
        dd(v, u);
        sub[u] += sub[v];
    }
}

void dfs(int u, int p) {
    static int ctr = 0;
    st[u] = ++ctr;
    at[ctr] = u;
    h[u] = h[p] + 1;

    ii bg;
    for (int v: g[u]) if (v != p) {
        bg = max(bg, ii(sub[v], v));
    }
    for (int v: g[u]) if (v != bg.S and v != p) {
        dfs(v, u);
        FOR (_, st[v], en[v]) {
            int it = at[_];
            cnt[h[it]]--;
        }
        pos = n;
    }
    if (bg.S) dfs(bg.S, u);
    for (int v: g[u]) if (v != bg.S and v != p) {
        FOR (_, st[v], en[v]) {
            int it = at[_];
            cnt[h[it]]++;
            if (cnt[h[it]] > cnt[pos] or (cnt[h[it]] == cnt[pos] and h[it] < pos)) pos = h[it];
        }
    }
    cnt[h[u]]++;
    if (cnt[h[u]] > cnt[pos] or (cnt[h[u]] == cnt[pos] and h[u] < pos)) pos = h[u];
    ans[u] = pos - h[u];

    en[u] = ctr;
}

int main()
{
    // ios::sync_with_stdio(0); cin.tie(0);

    // cin >> n;
    scanf("%d", &n);
    FOR (i, 1, n - 1) {
        int x, y;
        // cin >> x >> y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y), g[y].push_back(x);
    }
    pos = n;
    h[0] = -1;
    dd(1, 0);
    dfs(1, 0);
    FOR (i, 1, n) printf("%d\n", ans[i]);//cout << ans[i] << "\n";
    
    return 0;
}