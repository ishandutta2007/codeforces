#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int k, n;
        cin >> n >> k;
        vector<int> a(n + 1);
        set<int> s;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            s.insert(a[i]);
        }
        if (s.size() > k) {
            cout << -1 << '\n';
            continue;
        }
        int t = k - s.size();
        cout << k * n << '\n';
        for (int i = 1; i <= n; i++) {
            for (int e : s) cout << e << ' ';
            for (int j = 1; j <= t; j++) cout << 1 << ' ';
        }
        cout << '\n';
    }
    return 0;
}