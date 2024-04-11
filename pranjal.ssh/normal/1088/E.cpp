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
int n;
const int N = 3e5 + 10;
int a[N];
vi g[N];
pair<ll, int> NC[N];
pair<ll, pair<ll, int>> C[N];

pair<ll, pair<ll, int>> c(int, int);

pair<ll, int> mrg(pair<ll, int> x, pair<ll, int> y) {
    if (x.F < y.F) return y;
    if (x.F == y.F) x.S += y.S;
    return x;
}
pair<ll, int> worthy(pair<ll, pair<ll, int>> now2) {
    if (now2.S.F > now2.F) {

    } else if (now2.S.F == now2.F) {
        now2.S.S++;
    } else {
        now2.S.F = now2.F, now2.S.S = 1;
    }
    return now2.S;
}
pair<ll, int> nc(int u, int p) {
    auto &ans = NC[u];
    if (~ans.S) return ans;
    ans.F = -inf, ans.S = 0;
    for (int v: g[u]) if (v != p) {
        auto now1 = nc(v, u);
        
        auto now2 = c(v, u);

        ans = mrg(ans, max(now1, worthy(now2)));
    }
    return ans;
}

pair<ll, pair<ll, int>> c(int u, int p) {
    auto &ans = C[u];
    if (~ans.S.S) return ans;
    ans.S.F = -inf, ans.S.S = 0;
    ans.F = a[u];
    for (int v: g[u]) if (v != p) {
        auto now1 = nc(v, u);
        auto now2 = c(v, u);
        if (now2.F > 0) {
            ans.F += now2.F;
            ans.S = mrg(ans.S, now2.S);
        } else {
            ans.S = mrg(ans.S, max(now1, worthy(now2)));
        }
    }
    return ans;
}


int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    
    cin >> n;
    FOR (i, 1, n) cin >> a[i];
    FOR (i, 1, n - 1) {
        int x, y; cin >> x >> y;
        g[x].push_back(y), g[y].push_back(x);
    }
    memset(C, -1, sizeof C);
    memset(NC, -1, sizeof NC);
    auto ans = max(worthy(c(1,0)), nc(1,0));
    cout << ans.F*ans.S << " " << ans.S << "\n";

    return 0;
}