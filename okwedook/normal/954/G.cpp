#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

const ll inf = 1e9 + 7;

void checkmin(ll &a, ll b) {
    if (b < a) a = b;
}
ll n, r, k;
vector<ll> arr, checkarr;

bool check(ll m) {
    vector<ll> add(n, 0);
    ll kcheck = k;
    ll currsum = 0;
    for (int i = 0; i < n && kcheck >= 0; ++i) {
        currsum += add[i];
        if (arr[i] + currsum < m) {
            ll toadd = m - (currsum + arr[i]);
            if (i + r < n) add[i + r] -= toadd;
            currsum += toadd;
            kcheck -= toadd;
        }
    }
    return kcheck >= 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> r >> k;
    checkarr = arr = vector<ll> (n);
    for (auto &i : arr) cin >> i;
    ll ptr1 = 0, ptr2 = 0, summ = arr[0];
    for (ll i = 0; i < n; ++i) {
        while (ptr2 < n - 1 && i + r > ptr2) ++ptr2, summ += arr[ptr2];
        while (i - r > ptr1) summ -= arr[ptr1], ++ptr1;
        checkarr[i] = summ;
    }
    arr = checkarr;
    r = r * 2 + 1;
    ll left = 0, right = 2e18;
    while (right - left > 1) {
        ll m = right + left >> 1;
        if (check(m)) left = m;
        else right = m;
    }
    cout << left;
    return 0;
}