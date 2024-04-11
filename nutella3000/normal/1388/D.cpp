#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())
typedef long double ld;

const int inf = 1e9 + 7;
const int max_n = 1e6 + 4;

int n;
vector<int> gr[max_n];
int col[max_n];
vector<int> top;

int v_col = 1;

void dfs(int v) {
    if (col[v] != 0) return;
    //cout << v << endl;
    for(int i : gr[v]) {
        dfs(i);
    }
    col[v] = v_col++;
    top.emplace_back(v);
}

void solve() {
    cin >> n;
    vector<int> a(n);
    for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 0;i < n;i++) {
        int to;
        cin >> to;
        to--;
        if (to != -2) gr[i].emplace_back(to);
    }

    for(int i = 0;i < n;i++) {
        dfs(i);
    }

    int res = 0;
    vector<int> ans;
    for(int i = top.size() - 1;i >= 0;i--) {
        int v = top[i];
        if (a[v] < 0) continue;
        res += a[v];
        if (gr[v].size())
            a[gr[v][0]] += a[v];
        ans.emplace_back(v);
    }
    for(int i : top) {
        if (a[i] < 0) {
            ans.emplace_back(i);
            res += a[i];
        }
    }

    cout << res << endl;

    for(int i : ans) 
        cout << i + 1 << " ";

    cout << endl;
}


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    solve();
}