#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    int ans[t];

    for (int k = 0; k < t; k++) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        int c = 1;
        for (int i = 1; i < n; i++) {
            if (a[i] == a[i-1])
                continue;
            c += 1;
        }
        ans[k] = c;
    }

    for (int i = 0; i < t; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}