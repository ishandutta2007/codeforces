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


vector<int> T(2);
vector<vector<int>> nxt(10, vi(2));

int make_node() {
    T.emplace_back();
    FOR (i, 0, 9) nxt[i].emplace_back(0);
    return sz(T) - 1;
}

void insert(int no, string &s, int pos, int m) {
    if (pos == sz(s)) {
        T[no] += m;
        return;
    }
    int nno = nxt[s[pos] - '0'][no];
    if (nno == 0) nno = make_node();
    nxt[s[pos] - '0'][no] = nno;
    insert(nno, s, pos + 1, m);
}

int dp[510][510][11][11];
int f(int no, int up, int k, int pos) {
    if (no == 0 or pos == 10) {
        return T[no] * (1 + up);
    }
    int &ans = dp[no][up][k][pos];
    if (~ans) return ans;

    

    ans = inf;
    if (k) ans = min(ans, f(no, 0, k - 1, pos));

    if (nxt[pos][no] == 0) {
        return ans = min(ans, f(no, up, k, pos + 1));
    }

    FOR (it, 0, k) {
        ans = min(ans, f(no, up, k - it, pos + 1) + f(nxt[pos][no], up + 1, it, 0));
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int n, k; cin >> n >> k;
    int ans = 0;
    FOR (i, 0, n - 1) {
        string s; cin >> s; int m; cin >> m;
        ans += m;
        insert(1, s, 0, m);
    }
    memset(dp, -1, sizeof dp);
    cout << f(1, 0, k, 0) - ans;
    
    return 0;
}