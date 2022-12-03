#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast", "no-stack-protector")
//#pragma GCC target("sse4", "avx", "popcnt", "lzcnt", "sse3", "sse4.1", "sse4.2", "sse2", "tune=native")
//#pragma GCC optimize ("unroll-loops")

using namespace std;

typedef long double old;
typedef long long ll;

int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> pref(n);
    vector<int> suf(n);
    for (int i = 0; i < n; ++i) {
        pref[i] = (i ? pref[i - 1] : 0) + (s[i] == 'G');
        if (s[i] == 'S') {
            pref[i] = 0;
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        suf[i] = (i < n - 1 ? suf[i + 1] : 0) + (s[i] == 'G');
        if (s[i] == 'S') {
            suf[i] = 0;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int t = 1;
        if (i) {
            t += pref[i - 1];
        }
        if (i + 1 < n) {
            t += suf[i + 1];
        }
        ans = max(t, ans);
    }
    int k = 0;
    for (char c : s) {
        if (c == 'G') {
            ++k;
        }
    }
    ans = min(ans, k);
    cout << ans;
    return 0;
}