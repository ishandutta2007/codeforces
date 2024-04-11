#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 1e6 + 1;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    string s;
    cin >> s;
    vector<int> cnt(26);
    for (auto &x: s) cnt[x - 'a']++;
    int m;
    cin >> m;
    vector<int> b(m);
    range(i, m) cin >> b[i];
    vector<int> a(m);
    for (int c = 25; c >= 0; --c) {
        int k = 0;
        range(i, m) {
            if (b[i] == 0) k++;
        }
        if (cnt[c] < k) continue;
        vector<int> kek;
        range(i, m) {
            if (b[i] == 0) {
                a[i] = c;
                b[i]--;
                kek.push_back(i);
            }
        }
        range(i, m) {
            for (auto &j: kek) b[i] -= abs(i - j);
        }
    }
    range(i, m) cout << (char) ('a' + a[i]);
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}