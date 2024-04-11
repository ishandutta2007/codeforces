#include <bits/stdc++.h>
 
using namespace std;
 
//#define aidar asadulin
 
#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define pip pair<int, pii>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld long double
 
const int inf = 1e9 + 7;
const int max_n = 2e5 + 4;

int n;
int a[max_n];
vector<int> gr[max_n];
int sz[max_n];

pii dfs(int v) {
    pii res(0, 0);
    for(int i : gr[v]) {
        pii t = dfs(i);
        if (t.se <= res.se) {
            res.fi += t.fi + sz[i] * (res.se - t.se);
        }else {
            res.fi += t.fi + (t.se - res.se) * sz[v];
            res.se = t.se;
        }
        sz[v] += sz[i];
    }
    if (sz(gr[v]) == 0) sz[v]++;

    int num = min(a[v], res.fi);
    //if (v == 0) cout << res.fi << endl;
    res.fi -= num;
    a[v] -= num;
    if (a[v] > 0) {
        res.se += (a[v] + sz[v] - 1) / sz[v];
        res.fi += sz[v] - a[v] % sz[v];
        if (a[v] % sz[v] == 0) res.fi = 0;
    }

    //cout << v << " " << sz[v] << " " << res.fi << " " << res.se << endl;
    return res;
}

void solve() {
    cin >> n;
    for(int i = 1;i < n;i++) {
        int p;
        cin >> p;
        p--;
        gr[p].emplace_back(i);
    }
    for(int i = 0;i < n;i++)
        cin >> a[i];

    pii res = dfs(0);
    cout << res.se << endl;
}


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    solve();
}