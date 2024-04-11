#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

const ll inf = 1e9 + 7;

void checkmin(ll &a, ll b) {
    if (b < a) a = b;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;
    ll x = -1;
    for (ll i = 1; i < n; ++i) {
        ll d = abs(arr[i] - arr[i - 1]);
        if (d == 0) {
            cout << "NO";
            return 0;
        }
        if (d > 1) {
            if (x == -1) x = d;
            else if (d != x) {
                cout << "NO";
                return 0;
            }
        }
    }
    if (x != -1) {
        for (ll i = 1; i < n; ++i) {
            if ((arr[i] - 1) / x != (arr[i - 1] - 1) / x && abs(arr[i] - arr[i - 1]) == 1) {
                cout << "NO";
                return 0;
            }
        }
    } else {
        for (ll i = 0; i < n; ++i)
            x = max(x, arr[i]);
    }
    ll y = 0;
    for (auto i : arr) y = max(y, (i + x - 1) / x);
    if (x > 1e9 || y > 1e9) {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    cout << y << ' ' << x;
    return 0;
}