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

const int N = 501;
int dp[N][N];
string s; int n;

int f(int l,int r) {
    if (l > r) return 0;
    int &ans = dp[l][r];
    if (~ans) return ans;
    ans = r-l+1;
    FOR (i, l, r) {
        int j = i;
        while (j + 1 < r and s[j+1] == s[j]) ++j;
        int now = 1;
        if (l - 1 >= 0 and s[l-1] == s[i]) now = 0;
        if (r + 1 < n and s[r+1] == s[i]) now = 0;
        ans = min(ans, now + f(l, i - 1) + f(j + 1, r));
        i = j;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> s;
    memset(dp, -1, sizeof dp);
    cout << f(0, n-1) << "\n";
    
    return 0;
}