#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    sort(all(s));
    if (s[0] != s[k - 1]) {
        cout << s[k - 1] << '\n';
        return;
    }
    bool ok = 1;
    cout << s[k - 1];
    for (int i = k + 1; i < n; i++) {
        if (s[i] != s[i - 1]) ok = 0;
    }
    if (ok == 1) {
        int t = n - k;
        t = (t / k) + (t % k != 0);
        for (int i = 1; i <= t; i++) cout << s[k];
        cout << '\n';
        return;
    } else {
        for (int i = k; i < n; i++) cout << s[i];
        cout << '\n';
        return;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        solve();
    }
    return 0;
}