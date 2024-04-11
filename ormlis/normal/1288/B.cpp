

#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

using namespace std;

typedef long long ll;

const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 100001;
ll md = 998244353;

void solve() {
    ll A; string b; cin >> A >> b;
    int flag = 0;
    for(auto c: b) {
        if (c != '9') flag = 1;
    }
    cout << A * (b.size() - flag) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tests; cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}