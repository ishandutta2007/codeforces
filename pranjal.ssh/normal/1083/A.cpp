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

const int N = 3e5+10;
int w[N];
vector<ii> g[N];
ll down[N];
void dfs(int u) {    
    down[u] = w[u];
    for (ii e: g[u]) {
        int v = e.F, c = e.S;
        g[v].erase(find(all(g[v]), ii(u, c)));
        dfs(v);
        down[u] = max(down[u], w[u]+c+down[v]);
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    FOR (i, 1, n) cin >> w[i];
    FOR (i, 1, n - 1) {
        int u, v, c; cin >> u >> v >> c;
        g[u].emplace_back(v, -c);
        g[v].emplace_back(u, -c);
    }
    dfs(1);
    ll ans=0;
    FOR (u, 1, n) {
        vector<ll> st{0LL, 0LL};
        for (ii e: g[u]) {
            int v = e.F, c = e.S;
            st.emplace_back(c + down[v]);
        }
        sort(all(st)); reverse(all(st));
        ans = max(ans, st[0]+st[1]+w[u]);
    }
    cout << ans;
    
    return 0;
}