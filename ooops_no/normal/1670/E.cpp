#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long

mt19937 rnd(51);

const int N = (1LL << 17) + 5;
vector<pair<int,int>> g[N];
vector<int> a(N), b(N);
int now1 = -1, now2 = -1;

void dfs(int v, int p, bool f) {
    for (auto to : g[v]) {
        if (to.first != p) {
            if (f) {
                b[to.second] = now1++;
                a[to.first] = now2++;
            } else {
                b[to.second] = now2++;
                a[to.first] = now1++;
            }
            dfs(to.first, v, f ^ 1);
        }
    }
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LCOAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        n = (1 << n);
        now1 = 1, now2 = n;
        for (int i = 0; i < n; i++) g[i].clear();
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            g[a].pb({b, i});
            g[b].pb({a, i});
        }
        a[0] = now2++;
        dfs(0, -1, 0);
        cout << 1 << endl;
        for (int i = 0; i < n; i++) {
            cout << a[i] << ' ';
        }
        cout << endl;
        for (int i = 0; i < n - 1; i++) {
            cout << b[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}