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
    vector<int> a(n + 2, 0);
    bool ok1, ok2;
    ok1 = ok2 = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == k) ok1 = 1;
    }
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        if (a[i] >= k) v.pb(i);
    }
    for (int i = 1; i < v.size(); i++) {
        if (v[i] - v[i - 1] <= 2) ok2 = 1;
    }
    if (n == 1 && ok1) {
        cout << "yes\n";
        return;
    }
    cout << (ok1 && ok2 ? "yes\n" : "no\n");
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