#ifdef ONPC
    #define _GLIBCXX_DEBUG
    #define deb(a) cerr << "@@@@@@@ " << #a << " = " << a << endl;
#else
    #define deb(a)
#endif
#define sz(a) ((int)((a).size()))
#include <bits/stdc++.h>
#define char unsigned char

using namespace std;
mt19937 rnd(239);
// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;

const int N = 312345;

vector<int> g1[N], g2[N];

int tin[N], tout[N];

int curt = 0;

void dfs(int v) {
    tin[v] = curt++;
    for (int u : g2[v]) {
        dfs(u);
    }
    tout[v] = curt;
}

bool ispr(int pr, int v) {
    return tin[pr] <= tin[v] && tout[v] <= tout[pr];
}

int ans = 0;
set<pair<int, int>> q;

int tryAdd(int v) {
    auto it = q.lower_bound({tin[v], v});
    if (it != q.end() && ispr(v, it->second)) {
        return -1;
    }
    if (it != q.begin()) {
        it--;
        int u = it->second;
        if (ispr(u, v)) {
            q.erase(it);
        }
        q.insert({tin[v], v});
        return u;
    } else {
        q.insert({tin[v], v});
        return -1;
    }
}

void dfs2(int v) {
    int x = tryAdd(v);
    ans = max(ans, sz(q));
    for (int u : g1[v]) {
        dfs2(u);
    }
    q.erase({tin[v], v});
    if (x >= 0) {
        q.insert({tin[x], x});
    }
}

int solve() {
    int n;
    if (!(cin >> n)) {
        return 1;
    }
    ans = 0;
    curt = 0;
    q.clear();
    for (int i = 0; i < n; i++) {
        g1[i].clear();
        g2[i].clear();
    }
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        g1[x - 1].push_back(i);
    }
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        g2[x - 1].push_back(i);
    }
    dfs(0);
    dfs2(0);
    cout << ans << '\n';
    return 0;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int TET = 1e9;
    cin >> TET;
    for (int i = 1; i <= TET; i++) {
        if (solve()) {
            break;
        }
        #ifdef ONPC
            cout << "__________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}