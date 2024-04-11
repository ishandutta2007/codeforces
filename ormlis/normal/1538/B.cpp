#include <bits/stdc++.h>

#define range(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 4e5;



void solve() {
    int n; cin >> n;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    sort(all(a));
    ll sum = accumulate(all(a), 0ll);
    if (sum % n) {
        cout << "-1\n";
        return;
    }
    ll need = sum / n;
    int cnt = 0;
    while(cnt < n && a[n - 1 - cnt] > need) cnt++;
    cout << cnt << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tests = 1;
    // cout << setprecision(15) << fixed;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}