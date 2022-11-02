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
#define sz(a) ((int) a.size())
#define all(_v) _v.begin(), _v.end()
#define what_is(x) cout << #x << " is " << x << endl;
typedef long double ld;

const int inf = 1e15;

vector<int> f[3], g[3];
int cap;

int get(int type, int st) {
    int id = lower_bound(all(g[type]), st) - g[type].begin();
    return f[type][id] + max(g[type][id] - st - cap, 0ll);
}

void solve() {
    int n, m, last;
    cin >> last >> cap >> n >> m;
    for(int i = 0;i < n;i++) {
        int ty, v;
        cin >> ty >> v;
        if (v > last) continue;
        for(int j = ty - 1;j >= 0;j--)
            g[j].emplace_back(v);
    }

    for(int i = 0;i < 3;i++) {
        g[i].emplace_back(last);
        sort(all(g[i]));
        f[i].resize(sz(g[i]));

        for(int j = sz(g[i]) - 2;j >= 0;j--) {
            f[i][j] = f[i][j + 1] + max(0ll, g[i][j + 1] - g[i][j] - cap);
        }
    }

    for(int i = 0;i < m;i++) {
        int v;
        cin >> v;
        if (get(0, v)) cout << "-1 -1" << endl;
        else {
            int tmp = get(1, v);
            cout << tmp << " " << get(2, v) - tmp << endl;
        }
    }
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(3);

    solve();
}