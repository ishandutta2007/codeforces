#include <bits/stdc++.h>
using namespace std;

#define cerr cout
#define F first
#define S second
#define FOR(i,a,b) for (auto i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(auto i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 998244353;
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

const int N = 3e5 + 10;
vi g[N];
vi F[2][2][2][2][N];
void dfs(int u) {
    for (int v : g[u]) {
        g[v].erase(find(all(g[v]), u));
        dfs(v);
    }
}
inline int add(int x, int y) {x += y; if (x >= inf) x -= inf; return x;}
inline int mul(int x, int y) {return (x * 1LL * y) % inf;}
int f(int u, bool upm, bool upe, bool o, bool is, int pos) {
    if (sz(g[u]) == pos) {
        if (upm) return 1;
        if (upe and is) return 0;
        if (is) return 1;
        return o;
    }
    int &ans = F[upm][upe][o][is][u][pos];
    if (~ans) return ans;
    ans = 0;
    int v = g[u][pos];
    // delete
    ans = add(ans, mul(f(u, upm, upe, o, is, pos + 1), f(v, 0, 0, 0, 1, 0)));
    // keep e
    ans = add(ans, mul(f(u, upm, upe, o, 0, pos + 1), f(v, 0, 1, 0, 1, 0)));
    // keep o
    if (!upm and o == 0) ans = add(ans, mul(f(u, upm, upe, 1, 0, pos + 1), f(v, 1, 1, 0, 1, 0)));    
    
    return ans;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    FOR (i, 1, n - 1) {
        int u, v; cin >> u >> v;
        g[u].push_back(v), g[v].push_back(u);
    }
    dfs(1);
    FOR (i, 1, n) FOR (j, 0, 1) FOR (k, 0, 1) FOR (l, 0, 1) FOR (ll,0,1) F[j][k][l][ll][i] = vi(sz(g[i]), -1);
    cout << f(1, 0, 0, 0, 1, 0) << "\n";

    return 0;
}