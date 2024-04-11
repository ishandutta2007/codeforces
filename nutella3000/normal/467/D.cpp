#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pii pair<int, int>
#define mp make_pair
#define all(_v) _v.begin(), _v.end()
#define what_is(x) cout << #x << " is " << x << endl;
typedef long double ld;
 
const int inf = 1e16;
const int max_n = 2e5 + 1;

map<string, int> a;
pii b[max_n];

int n;
int s[max_n];


vector<int> gr[max_n], g[max_n];
pii dp[max_n];

vector<int> order;
bool used[max_n];
int comp[max_n];

void dfs(int v) {
    if (used[v]) return;
    used[v] = 1;
    for(int i : g[v])
        dfs(i);
    order.emplace_back(v);
}

void color(int v, int col) {
    if (comp[v] != 0) return;
    comp[v] = col;
    dp[col] = min(dp[col], b[v]);
    for(int i : gr[v]) {
        if (comp[i] != 0) dp[col] = min(dp[col], dp[comp[i]]);
        color(i, col);
    }
}

int cnt_r(string s) {
    int res = 0;
    for(char i : s) 
        res += i == 'r';
    return res;
}

void add_a(string s) {
    if (!a.count(s)) {
        b[a.size()] = mp(cnt_r(s), s.size());
        a[s] = a.size();
    }
}

string tolower(string& s) {
    for(int i = 0;i < s.size();i++) {
        s[i] = tolower(s[i]);
    }
    return s;
}

void solve() {
    for(int i = 0;i < max_n;i++)
        dp[i] = {inf, inf};
    cin >> n;
    string s1, s2;
    for(int i = 0;i < n;i++) {
        cin >> s1;
        tolower(s1);
        add_a(s1);
        s[i] = a[s1];
    }

    int m;
    cin >> m;
    for(int i = 0;i < m;i++) {
        cin >> s1 >> s2;
        tolower(s1);
        tolower(s2);
        add_a(s1);
        add_a(s2);
        gr[a[s1]].emplace_back(a[s2]);
        g[a[s2]].emplace_back(a[s1]);
    }

    for(int i = 0;i < a.size();i++) {
        dfs(i);
    }
    int col = 0;
    for(int i = order.size() - 1;i >= 0;i--) {
        color(order[i], ++col);
    }

    //cout << a["zz"] << " " << comp[a["zz"]] << " "<< dp[comp[a["zz"]]].se << endl;

    pii res;
    for(int i = 0;i < n;i++) {
        pii temp = dp[comp[s[i]]];
        //cout << temp.fi << " " << temp.se << endl;
        res.fi += temp.fi; 
        res.se += temp.se;
    }

    cout << res.fi << " " << res.se << endl;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    solve();
}