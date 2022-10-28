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

ll palin(const basic_string<ll>& s) {
    int n = sz(s);
    vi odd(n), even(n);

    ll ans = 0;
    int l, r;
    // Odd case
    l = r = -1;
    for (int i = 0; i < n; i++) {
        int cur = 1;
        if (i < r)
            cur = min(r - i + 1, odd[l + r - i]);
        while (i + cur < n && i - cur >= 0 && s[i - cur] == s[i + cur])
            cur++;
        odd[i] = cur;
        if (i + cur - 1 > r) {
            l = i - cur + 1;
            r = i + cur - 1;
        }
        ans += odd[i];
    }

    // Even case
    l = r = -1;
    for (int i = 0; i < n; i++) {
        int cur = 0;
        if (i < r)
            cur = min(r - i + 1, even[l + r - i + 1]);
        while (i + cur < n && i - 1 - cur >= 0 && s[i - 1 - cur] == s[i + cur])
            cur++;
        even[i] = cur;
        if (i + cur - 1 > r) {
            l = i - cur;
            r = i + cur - 1;
        }
        ans += even[i];
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;
    vector<string> a(n);
    FOR (i, 0, n - 1) {
        cin >> a[i];
    }
    vector<ll> xx(26);
    FOR (i, 0, 25) xx[i] = abs((rand()*1LL*rand()*1LL*rand()*1LL*rand()) % inf);

    ll ans = 0;
    FOR (i, 0, m - 1) {
        vector<vi> f(n, vi(26));
        vector<int> b(n);
        basic_string<ll> h(n, 0);
        FOR (j, i, m - 1) {
            FOR (k, 0, n - 1) {
                h[k] ^= (xx[a[k][j]-'a'] * f[k][a[k][j]-'a']) % inf;
                f[k][a[k][j]-'a']++;
                h[k] ^= (xx[a[k][j]-'a'] * f[k][a[k][j]-'a']) % inf;
                b[k] ^= (1 << (a[k][j]-'a'));
            }
            int prv = 0;
            FOR (k, 0, n) {
                if (k < n and __builtin_popcount(b[k]) <= 1) {
                    continue;
                } else {
                    // if (k > prv) pr(i, j, prv, k - 1);
                    ans += palin(h.substr(prv, k - prv));
                    prv = k + 1;
                }
            }
        }
    }
    cout << ans << "\n";

    return 0;
}