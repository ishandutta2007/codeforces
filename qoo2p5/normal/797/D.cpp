#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9 + 123;
const ll LINF = (ll) 1e18 + 123;

#define sz(x) (int) (x).size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define all(x) (x).begin(), (x).end()

void run();

int main() {
#ifndef LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif
    run();
    return 0;
}

const int N = (int) 1e5 + 123;

int n;
int v[N], l[N], r[N], p[N];
map<int, int> cnt;
set<int> ok;
multiset<int> L, R;

void dfs(int u) {
    if ((R.empty() || *R.rbegin() < v[u]) && (L.empty() || *L.begin() > v[u])) {
        ok.insert(v[u]);
    }
    if (l[u] != -1) {
        L.insert(v[u]);
        dfs(l[u]);
        L.erase(L.find(v[u]));
    }
    if (r[u] != -1) {
        R.insert(v[u]);
        dfs(r[u]);
        R.erase(R.find(v[u]));
    }
}

void run() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> l[i] >> r[i];
        if (l[i] != -1) {
            p[l[i]] = i;
        }
        if (r[i] != -1) {
            p[r[i]] = i;
        }
        cnt[v[i]]++;
    }
    
    int root = -1;
    for (int i = 1; i <= n; i++) {
        if (!p[i]) root = i;
    }
    dfs(root);
    
    int res = 0;
    for (auto &it : cnt) {
        if (!ok.count(it.first)) {
            res += it.second;
        }
    }
    cout << res << "\n";
}