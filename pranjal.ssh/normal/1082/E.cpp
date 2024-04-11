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

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int n, c; cin >> n >> c;
    vi a(n + 1);
    vector<vi> mp(5e5+1);
    vi f(n + 1);
    FOR (i, 1, n) {
        cin >> a[i], mp[a[i]].push_back(i);
        if (a[i] == c) f[i]++;
        f[i] += f[i-1];
    }
    int ans = f[n];
    FOR (i, 1, 5e5) if (i != c and sz(mp[i])) {
        int cur = 0, suff = 0;
        FOR (j, 0, sz(mp[i]) - 1) {
            if (j) {
                int val = -f[mp[i][j]] + f[mp[i][j-1]];
                suff = max(suff + val, val);
                cur = max(cur, suff);
            }
            int val = 1;
            suff = max(suff + val, val);
            cur = max(cur, suff);
        }
        ans = max(ans, f[n] + cur);
    }
    cout << ans;
    
    return 0;
}