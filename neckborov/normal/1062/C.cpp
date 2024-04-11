#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//#pragma GCC optimize ("unroll-loops")

using namespace std;

typedef long double ld;
typedef long long ll;

const ll M = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<ll> pref(n + 1);
    for (int i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1] + s[i - 1] - '0';
    }
    vector<ll> calc(n + 1);
    calc[0] = 1;
    for (int i = 1; i <= n; ++i) {
        calc[i] = calc[i - 1] * 2 % M;
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        ll kek = pref[r] - pref[l - 1];
        ll zero = r - l + 1 - kek;
        ll ans = calc[kek] - 1;
        ans = (ans + ans * (calc[zero] - 1)) % M;
        cout << (ans + M) % M << '\n';

    }
    return 0;
}