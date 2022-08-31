#include <bits/stdc++.h>
#include <cstdlib>
#include <string>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 1e6 + 1;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    ll n; cin >> n;
    vector<ll> d;
    for(ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            d.push_back(i);
            while(n % i == 0) {
                n /= i;
            }
        }
    }
    if (n != 1) d.push_back(n);
    if (d.size() != 1) {
        cout << 1 << '\n';
    } else {
        cout << d[0] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
//    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}