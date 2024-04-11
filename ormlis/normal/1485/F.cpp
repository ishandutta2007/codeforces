#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < (n); ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

const ll INF = 1e18;

using namespace std;
const int md = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> b(n);
    range(i, n) cin >> b[i];
    int answer = 1;
    map<ll, int> sm;
    sm[0] = 1;
    ll p = b[0];
    for (int i = 1; i < n; ++i) {
        int cur = (answer - sm[p] + md) % md;
        answer += cur;
        answer %= md;
        sm[p] += cur;
        sm[p] %= md;
        p += b[i];
    }
    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}