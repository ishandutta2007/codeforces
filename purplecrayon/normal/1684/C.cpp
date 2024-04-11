#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 1e9+7;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto& r : a) for (auto& c : r) cin >> c;

    ar<int, 2> need{-1, -1};
    for (auto r : a) {
        if (std::is_sorted(r.begin(), r.end())) continue;
        auto sr = r; sort(sr.begin(), sr.end());

        set<int> s;
        for (int i = 0; i < m; i++) if (sr[i] != r[i]) s.insert(i);

        if (sz(s) > 5) {
            cout << -1 << '\n';
            return;
        }
        bool done = 0;
        for (int x : s) {
            for (int y : s) {
                auto nr = r;
                swap(nr[x], nr[y]);
                if (std::is_sorted(nr.begin(), nr.end())) {
                    if (need == ar<int, 2>{-1, -1}) need = {x, y};
                    else if (need != ar<int, 2>{x, y}) {
                        cout << -1 << '\n';
                        return;
                    }
                    done = 1;
                    break;
                }
            }
            if (done) break;
        }
        if (!done) {
            cout << -1 << '\n';
            return;
        }
    }
    for (auto r : a) {
        if (need != ar<int, 2>{-1, -1}) {
            swap(r[need[0]], r[need[1]]);
        }
        if (!std::is_sorted(r.begin(), r.end())) {
            cout << -1 << '\n';
            return;
        }
    }
    if (need == ar<int, 2>{-1, -1}) cout << 1 << ' ' << 1 << '\n';
    else cout << need[0]+1 << ' ' << need[1]+1 << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}