#include <bits/stdc++.h>
using namespace std;

#define cerr cout
#define F first
#define S second
#define FOR(i,a,b) for (auto i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(auto i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 9;
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

int dp[101][10001];
int C[101][101];
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vi f(101);
    set<int> s;
    vi a(n + 1); FOR (i, 1, n) cin >> a[i], f[a[i]]++, s.insert(a[i]);
    FOR (i, 0, 100) {
        C[i][0] = 1;
        FOR (j, 1, i) {
            C[i][j] = C[i-1][j] + C[i-1][j-1];
            if (C[i][j] >= inf) C[i][j] -= inf;
        }
    }

    dp[0][0] = 1;
    int sum = 0;
    FOR (i, 1, n) {
        sum += a[i];
        NFOR (k, i, 1) {
            NFOR (s, sum, a[i]) {
                dp[k][s] += dp[k - 1][s - a[i]];
                if (dp[k][s] >= inf) dp[k][s] -= inf;
            }
        }
    }

    int ans = 0;
    FOR (i, 1, 100) if (f[i]) {
        FOR (it, 1, f[i]) {
            if (dp[it][i*it] == C[f[i]][it]) {
                ans = max(ans, it);
                if (it == f[i] and sz(s) == 2) ans = n;
            }
        }
    }
    cout << ans;
    
    return 0;
}