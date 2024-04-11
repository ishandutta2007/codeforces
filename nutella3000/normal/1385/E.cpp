#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e15 + 7;
const int max_n = 2e5 + 1;

int n;
vector<int> gr[max_n];
int used[max_n];
int color[max_n];

bool dfs(int v, int& col) {
    //cout << "begin " << col << " " << v << endl;
    if (used[v] == 1) return false;
    if (used[v] == 2) return true;
    used[v] = 1;
    for(int i : gr[v]) {
        if (!dfs(i, col)) return false;
    }

    //cout << "end " << col << " " << v << endl;
    color[v] = col++;
    used[v] = 2;
    return true;
}

void solve() {
    int m;
    cin >> n >> m;

    for(int i = 0;i < n;i++) {
        used[i] = 0;
        gr[i].clear();
    }

    vector<int> t(m), x(m), y(m);
    for(int i = 0;i < m;i++) {
        cin >> t[i] >> x[i] >> y[i];
        x[i]--; y[i]--;
        if (t[i] == 1) {
            gr[x[i]].emplace_back(y[i]);
        }
    }

    int col = 0;
    bool good = true;
    for(int i = 0;i < n;i++) {
        good &= dfs(i, col);
    }
    //cout << "color: " << endl;
    //for(int i = 0;i < n;i++) cout << color[i] << " ";
    //cout << endl;

    if (!good) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        for(int i = 0;i < m;i++) {
            if (color[y[i]] > color[x[i]]) swap(x[i], y[i]);
            cout << x[i] + 1 << " " << y[i] + 1 << endl;
        }
    }
}



signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}