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

const int N = 5e3 + 10;
ll dp[N][N];
int a[N];
multiset<int> pls;
int n, k, x;

ll f(int pos, int l) {
    if (pos == n) return l == 1 ? a[pos] : -1e18;
    if (l == 1) return n - pos >= k ? -1e18 : a[pos];

    ll &ans = dp[pos][l];
    if (~ans) return ans;
    ans = -1e18;
    FOR (it, pos + 1, min(n, pos + k)) {
        ans = max(ans, a[pos] + f(it, l - 1));
    }

    return ans;
}

void g(int pos, int l) {
    pls.erase(pls.find(a[pos]));
    if (l == 1) return;
    FOR (it, pos + 1, min(n, pos + k)) {
        if (f(pos, l) == a[pos] + f(it, l - 1)) {
            g(it, l - 1);
            return;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k >> x;
    memset(dp, -1, sizeof dp);
    FOR (i, 1, n) cin >> a[i];
    pls = multiset<int>(a+1, a+n+1);

    if (x < n/k) {
        cout << "-1\n";
    } else {
        ll h = -1e18;
        ll mn = min(x, 2*(n/k + 2));
        // mn = 2;
        FOR (i, 1, k) h = max(h, f(i, mn));
        assert(h != -1e18);

        FOR (i, 1, k) if (h == f(i, mn)) {
            ll lft = x - mn;
            g(i, mn);
            while (lft--) {
                h += *pls.rbegin();
                pls.erase(--pls.end());
            }
            cout << h << "\n";
            return 0;
        }
    }
    
    return 0;
}