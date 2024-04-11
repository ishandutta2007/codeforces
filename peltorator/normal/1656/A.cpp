



#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << max_element(a.begin(), a.end()) - a.begin() + 1 << ' ' << min_element(a.begin(), a.end()) - a.begin() + 1 << '\n';
    }
    return 0;
}