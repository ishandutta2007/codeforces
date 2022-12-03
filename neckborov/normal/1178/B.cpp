//#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;
    ll cnt = 0;
    ll l = 0;
    ll ans = 0;
    for (int i = 0; i + 1 < s.length(); i++) {
        if (s[i] == 'v' && s[i + 1] == 'v') {
            cnt++;
        }
    }
    for (int i = 0; i + 1 < s.length(); i++) {
        if (s[i] == 'v' && s[i + 1] == 'v') {
            l++;
        }
        if (s[i] == 'o') {
            ans += l * (cnt - l);
        }
    }
    cout << ans;
    return 0;
}