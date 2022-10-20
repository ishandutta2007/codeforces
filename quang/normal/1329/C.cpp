#include <bits/stdc++.h>

using namespace std;

const int N = (1 << 20) + 10;

int h, g;
int a[N];
vector<int> res;

void remove(int u) {
    if ((u << 1) >= (1 << h) || (a[u << 1] == 0 && a[u << 1 | 1] == 0)) {
        a[u] = 0;
    } else {
        int v = a[u << 1] > a[u << 1 | 1] ? u << 1 : u << 1 | 1;
        a[u] = a[v];
        remove(v);
    }
}

bool check(int u, int v) {
    if ((u << 1) >= (1 << h) || (a[u << 1] == 0 && a[u << 1 | 1] == 0)) {
        return v > g;
    }
    int w = a[u << 1] > a[u << 1 | 1] ? u << 1 : u << 1 | 1;
    return check(w, v + 1);
}

void dfs(int u, int v) {
    if (u >= (1 << h) || a[u] == 0) return;
    while (check(u, v)) {
        remove(u);
        res.push_back(u);
    }
    dfs(u << 1, v + 1);
    dfs(u << 1 | 1, v + 1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> h >> g;
        for (int i = 1; i < (1 << h); i++) {
            cin >> a[i];
        }
        res.clear();
        dfs(1, 1);
        cout << accumulate(a + 1, a + (1 << g), 0ll) << '\n';
        for (int u : res) cout << u << ' ';
            cout << '\n';
    }  
    return 0;
}