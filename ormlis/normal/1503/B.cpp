#include <bits/stdc++.h>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;

const int INFi = 2e9 + 5;
const int maxN = 3e5 + 100;
const int md = 1e9 + 7;
const ll INF = 2e18;

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> c1, c2;
    range(i, n) range(j, n) {
        if ((i + j) % 2) c1.push_back({i, j});
        else c2.push_back({i, j});
    }
    range(i, n * n) {
        int x; cin >> x;
        if (x != 1 && !c1.empty()) {
            cout << "1 " << c1.back().first + 1 << ' ' << c1.back().second + 1 << endl;
            c1.pop_back();
            continue;
        }
        if (x != 2 && !c2.empty()) {
            cout << "2 " << c2.back().first + 1 << ' ' << c2.back().second + 1 << endl;
            c2.pop_back();
            continue;
        }
        if (!c1.empty()) {
            cout << "3 " << c1.back().first + 1 << ' ' << c1.back().second + 1 << endl;
            c1.pop_back();
            continue;
        }
        if (!c2.empty()) {
            cout << "3 " << c2.back().first + 1 << ' ' << c2.back().second + 1 << endl;
            c2.pop_back();
            continue;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    //cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}