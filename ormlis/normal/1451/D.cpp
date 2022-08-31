#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

// using namespace __gnu_pbds;
using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 2e5 + 1;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    ll d, k;
    cin >> d >> k;
    ll steps = d / k;
    vector<ll> dist(steps + 1);
    range(i, steps + 1) {
        ll v = d * d - 1ll * (i * k) * (i * k);
        ll e = sqrt(v);
        while (e * e < v) e++;
        while (e * e > v) e--;
        dist[i] = e / k;
        if (dist[i] < i) {
            if ((i + dist[i]) % 2) {
                cout << "Ashish\n";
            } else {
                cout << "Utkarsh\n";
            }
            return;
        }
        if (dist[i] > i) continue;
        cout << "Utkarsh\n";
        return;
    }
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