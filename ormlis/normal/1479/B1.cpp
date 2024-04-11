#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define ar array
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()


typedef long long ll;
typedef long double ld;
using namespace std;

// using namespace __gnu_pbds;

const ll INF = 1e18 + 5;
const int INFi = 2e9;
const int maxN = 1e6 + 1000;
const int md = 1e9 + 123;
const int md2 = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    int last = -1;
    vector<pair<int, int>> second = {{0, -1}};
    range(i, n) {
        int x;
        cin >> x;
        vector<pair<int, int>> nxt;
        for (auto &[res, c] : second) {
            nxt.emplace_back(res + (c != x), last);
            nxt.emplace_back(res + (last != x), c);
        }
        sort(rall(nxt));
        nxt.resize(unique(all(nxt)) - nxt.begin());
        while (nxt.back().first != nxt[0].first) nxt.pop_back();
        while(nxt.size() > 2) nxt.pop_back();
        second = nxt;
        last = x;
    }
    cout << second.front().first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}