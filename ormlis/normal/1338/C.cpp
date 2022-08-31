#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 2e5 + 1;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

ll find1(ll n) {
    ll x = n;
    ll i = 1;
    while(x >= 4) {
        x /= 4;
        i *= 4;
    }
    n -= i;
    i += n / 3;
    return i;
}

ll find2(ll n) {
    ll n1 = find1(n);
    int k = (63 - __builtin_clzll(n1)) / 2;
    vector<int> v;
    range(_, k) {
        v.push_back(n1 % 4);
        n1 /= 4;
    }
    reverse(all(v));
    ll ans = 2;
    for(auto &x: v) {
        ans *= 4;
        if (x == 0) {
            ans += 0;
        }
        if (x == 1) {
            ans += 2;
        }
        if (x == 2) {
            ans += 3;
        }
        if (x == 3) {
            ans += 1;
        }
    }
    return ans;
}

void solve() {
    ll n; cin >> n;
    if (n % 3 == 1) {
         cout << find1(n) << "\n";
    } else if (n % 3 == 2) {
        cout << find2(n) << "\n";
    } else {
        cout << (find1(n - 2) ^ find2(n - 1)) << "\n";
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}