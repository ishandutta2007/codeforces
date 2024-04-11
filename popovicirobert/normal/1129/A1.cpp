#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

const ll INF = 1e18;
const int MAXN = 5000;

vector <int> g[MAXN + 1];

inline int get(int a, int b, int n) {
    if(a <= b) return b - a;
    return n + b - a;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    for(int start = 1; start <= n; start++) {
        ll cur = 0;
        for(i = 1; i <= n; i++) {
            if(g[i].empty()) {
                continue;
            }
            ll mn = INF;
            for(auto it : g[i]) {
                mn = min(mn, 1LL * get(i, it, n));
            }
            cur = max(cur, 1LL * (g[i].size() - 1) * n + get(start, i, n) + mn);
        }
        cout << cur << " ";
    }
    //cin.close();
    //cout.close();
    return 0;
}