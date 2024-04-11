#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 4e18;
const int INFi = 2e9;
const int maxN = 5000 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    if (n * a != m * b) {
        cout << "NO\n";
        return;
    }
    vector<pair<int, int>> nxt;
    range(i, m) nxt.emplace_back(0, i);
    cout << "YES\n";
    range(i, n) {
        vector<int> current(m, 0);
        range(j, a) {
            current[nxt[j].second] = 1;
            nxt[j].first++;
        }
        sort(all(nxt));
        range(j, m) cout << current[j];
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}