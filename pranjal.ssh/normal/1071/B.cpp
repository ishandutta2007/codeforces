#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define FOR(i,a,b) for (auto i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(auto i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;
string to_string(string s) { return '"' + s + '"';}
string to_string(const char s) { return string(1, s);}
string to_string(const char* s) { return to_string((string) s);}
string to_string(bool b) { return (b ? "true" : "false");}
template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A> string to_string(A v) {bool f = 1; string r = "{"; for (const auto &x : v) {if (!f)r += ", "; f = 0; r += to_string(x);} return r + "}";}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {cerr << " " << to_string(H); debug_out(T...);}
#define pr(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

vector<string> a;
int n, k;
int dp[2111][2111];
int f(int i, int j) {
    int &ans = dp[i][j];
    if (~ans) return ans;
    ans = a[i][j] == 'a';
    if (i - 1 >= 0) ans = max(ans, (a[i][j] == 'a') + f(i - 1, j));
    if (j - 1 >= 0) ans = max(ans, (a[i][j] == 'a') + f(i, j - 1));
    return ans;
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    a.resize(n);
    FOR (i, 0, n - 1) {
        cin >> a[i];
    }
    memset(dp, -1, sizeof dp);
    vector<ii> cons;
    string ans;
    FOR (i, 0, n - 1) {
        FOR (j, 0, n - 1) {
            int l = i + 1 + j + 1 - 1;
            int h = f(i, j);
            if (h + k >= l) {
                cons.emplace_back(i, j);
            }
        }
    }
    if (cons.empty()) {
        cons.emplace_back(0, 0);
        ans += a[0][0];
    } else {
        int L = 0;
        for (auto it: cons) L = max(L, it.F+it.S+1);
        cons.resize(remove_if(all(cons), [&](ii x) {return x.F+x.S+1 != L;}) - cons.begin());
        ans = string(L, 'a');
    }
    vector<ii> ncons;
    while (1) {
        if (cons.back() == ii(n - 1, n - 1)) break;
        char mn = 'z';
        ncons.clear();
        for (auto it : cons) {
            if (it.F + 1 < n) mn = min(mn, a[it.F + 1][it.S]);
            if (it.S + 1 < n) mn = min(mn, a[it.F][it.S + 1]);
        }
        
        ans.push_back(mn);
        for (auto it : cons) {
            if (it.F + 1 < n and a[it.F + 1][it.S] == mn) ncons.emplace_back(it.F + 1, it.S);
            if (it.S + 1 < n and a[it.F][it.S + 1] == mn) ncons.emplace_back(it.F, it.S + 1);
        }
        sort(all(ncons)); ncons.resize(unique(all(ncons))-ncons.begin());
        ncons.swap(cons);
    }
    cout << ans << "\n";

    return 0;
}