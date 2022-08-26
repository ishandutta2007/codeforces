#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
using namespace std;

const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 200001;
ll md = 1000000007;

vector<int> g[maxN];

struct Trip {
    int a=0, b=0;
    int r1=0, r2=0;
    int lca_r=0;
};

bool operator<(Trip &a, Trip&b) {
    return a.r1 + a.r2 + a.lca_r < b.r1 + b.r2 + b.lca_r;
}

int a1, b1, c1;
int answer=0;

Trip compare(Trip &a, Trip &b) {
    Trip res1 = {a.a, b.a, a.r1 + a.lca_r, b.r1 + b.lca_r, 0};
    Trip res2 = {a.a, b.b, a.r1 + a.lca_r, b.r2 + b.lca_r, 0};
    Trip res3 = {a.b, b.a, a.r2 + a.lca_r, b.r1 + b.lca_r, 0};
    Trip res4 = {a.b, b.b, a.r2 + a.lca_r, b.r2 + b.lca_r, 0};
    if (res1 < res2) res1 = res2;
    if (res1 < res3) res1 = res3;
    if (res1 < res4) res1 = res4;
    if (res1 < a) res1 = a;
    if (res1 < b) res1 = b;
    return res1;
}

void check(Trip &a, Trip &b) {
    int res1 = a.r1 + a.r2 + a.lca_r + b.r1 + b.lca_r;
    int res2 = a.r1 + a.r2 + a.lca_r + b.r2 + b.lca_r;
    int res3 = a.r1 + a.lca_r + b.r1 + b.r2 + b.lca_r;
    int res4 = a.r2 + a.lca_r + b.r1 + b.r2 + b.lca_r;
    if (res1 >= answer) {
        answer = res1;
        a1 = a.a;
        b1 = a.b;
        c1 = b.a;
    }
    if (res2 >= answer) {
        answer = res2;
        a1 = a.a;
        b1 = a.b;
        c1 = b.b;
    }
    if (res3 >= answer) {
        answer = res3;
        a1 = a.a;
        b1 = b.a;
        c1 = b.b;
    }
    if (res4 >= answer) {
        answer = res4;
        a1 = a.b;
        b1 = b.a;
        c1 = b.b;
    }
}

Trip dfs(int v, int p) {
    Trip a = Trip(), b = Trip(), d = Trip();
    a.a = a.b = b.a = b.b = d.a = d.b = v;
    for(auto u: g[v]) {
        if (u == p) continue;
        auto c = dfs(u, v);
        c.lca_r++;
        if (a < c) {
            d = b;
            b = a;
            a = c;
        } else if (b < c) {
            d = b;
            b = c;
        } else if (d < c) {
            d = c;
        }
    }
    check(a, b);
    check(b, d);
    check(a, d);
    auto s1 = compare(a, b);
    check(s1, d);
    s1 = compare(s1, d);
    return s1;
}

void solve() {
    int n; cin >> n;
    range(i, n - 1) {
        int a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0, -1);
    while (a1 == b1 || a1 == c1) {
        a1 = (a1 + 1) % n;
    }
    while(b1 == c1 || b1 == a1) {
        b1 = (b1 + 1) % n;
    }
    cout << answer << '\n';
    cout << a1 + 1 << ' ' << b1 + 1 << ' ' << c1 + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}