






#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        int k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        set<int> q;
        for (int x : a) {
            q.insert(x);
        }
        bool ok = false;
        for (int i = 0; i < n; i++) {
            if (q.count(a[i] - k)) {
                ok = true;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}