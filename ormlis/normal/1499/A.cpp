#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

typedef long long ll;

using namespace std;
//using namespace __gnu_pbds;

const int INFi = 2e9 + 5;
const int maxN = 1e7 + 5;
const int md = 1e9 + 7;
const ll INF = 2e18;

void solve() {
    int n, k1, k2; cin >> n >> k1 >> k2;
    int w, b; cin >> w >> b;
    w -= (k1 + k2) / 2;
    b -= (n - k1 + n - k2) / 2;
    if (w > 0 || b > 0) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}