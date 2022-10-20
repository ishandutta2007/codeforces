#include <bits/stdc++.h>

using namespace std;

const int N = 300010;
const int INF = 1e9;

int n, m;
vector<int> a[N], b[N];
int aa[N], bb[N];
bool used[N];
int deg[N];
int num[N];

vector<int> getList(vector<int> a[]) {
    for (int i = 1; i <= n; i++) {
        deg[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int v : a[i]) {
            deg[v]++;
        }
    }
    vector<int> res;
    res.reserve(n);
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) {
            res.push_back(i);
        }
    }
    for (int i = 0; i < res.size(); i++) {
        int u = res[i];
        for (int v : a[u]) {
            deg[v]--;
            if (deg[v] == 0) {
                res.push_back(v);
            }
        }
    }
    return res;
}

void go(vector<int> a[], vector<int> b[], int d[]) {
    for (int i = 1; i <= n; i++) {
        num[i] = 0;
        used[i] = 0;
    }
    vector<int> lsA = getList(a);
    // for (int u : lsA) {
    //     cerr << u << " ";
    // }
    // cerr << endl;
    int cnt = 0;
    unordered_set<int> s;
    // s.reserve(n + 1);
    vector<int> dis(n + 1, -INF);
    vector<int> pref(n + 1, 0);
    for (int i = 0; i < lsA.size(); i++) {
        int u = lsA[i];
        for (int v : b[u]) {
            if (!used[v]) {
                used[v] = 1;
                cnt++;
                s.erase(v);
            }
        }
        if (cnt == i) {
            dis[u] = cnt;
        } else if (cnt == i - 1) {
            dis[u] = cnt;
            pref[u] = *s.begin();
            num[pref[u]]++;
            num[u]++;
        }
        s.insert(u);
    }
    for (int i = 1; i <= n; i++) {
        if (pref[i] != 0 && num[i] == 1) {
            a[i].push_back(pref[i]);
        }
        used[i] = 0;
    }
    vector<int> lsB = getList(a);
    vector<int> dis2(n + 1, -INF);
    // for (int u : lsB) {
    //     cerr << u << " ";
    // }
    // cerr << endl;
    cnt =0;
    for (int i = 0; i < lsB.size(); i++) {
        int u = lsB[i];
        for (int v : b[u]) {
            if (!used[v]) {
                used[v] = 1;
                cnt++;
            }
        }
        if (cnt >= i - 1) {
            dis2[u] = cnt;
        }
        // cerr << u << " " << dis2[u] << endl;
    }
    for (int i = 1; i <= n; i++) {
        if (dis[i] == dis2[i]) {
            d[i] = dis[i];
        } else {
            d[i] = -INF;
        }
        // cerr << i << " " << d[i] << endl;
    }
    for (int i = 1; i <= n; i++) {
        if (pref[i] != 0 && num[i] == 1) {
            a[i].pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        b[v].push_back(u);
    }

    go(a, b, aa);
    go(b, a, bb);

    // for (int i = 1; i <= n; i++) {
    //     cerr << i << " " << aa[i] << " " << bb[i] << endl;
    // }

    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (aa[i] + bb[i] + 1 >= n - 1) {
            res++;
        }
    }
    cout << res << endl;
    return 0;
}