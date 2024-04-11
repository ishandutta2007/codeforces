#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 5e5 + 1;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n; cin >> n;
    vector<int> s(n);
    range(i, n) cin >> s[i];
    sort(all(s));
    int c = 0;
    int prev = 1;
    for(auto &x: s) {
        while(x != prev) {
            prev *= 2;
            c /= 2;
            if (prev == 2048 && c) {
                cout << "YES\n";
                return;
            }
        }
        c++;
        if (prev == 2048 && c) {
            cout << "YES\n";
            return;
        }
    }
    while (prev < 2048) {
        prev *= 2;
        c /= 2;
    }
    if (prev == 2048 && c) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}