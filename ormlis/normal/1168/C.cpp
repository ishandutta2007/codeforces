#include <bits/stdc++.h>

#define range(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;
typedef long double ld;


void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    int LG = 20;
    vector<vector<int>> to(n, vector<int> (LG, n));
    vector<vector<int>> mindx(LG, vector<int> (LG, n));
    for(int i = n - 1; i >= 0; --i) {
        vector<int> bts;
        range(j, LG) if ((1 << j) & a[i]) bts.push_back(j);
        vector<int> res(LG, n);
        for(auto &j : bts) {
            range(e, LG) {
                res[e] = min(res[e], mindx[j][e]);
            }
            res[j] = min(res[j], i);
        }
        for(auto &j : bts) {
            mindx[j] = res;
        }
        to[i] = res;
    }
    range(_, q) {
        int x, y; cin >> x >> y;
        x--;
        y--;
        bool ok = false;
        range(j, LG) {
            if ((1 << j) & a[y]) {
                if (to[x][j] <= y) {
                    ok = true;
                }
            }
        }
        cout << (ok ? "Shi\n" : "Fou\n");
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}