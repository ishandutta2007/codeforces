#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    vector<int> ans(t, 0);

    for (int T = 0; T < t; T++) {
        int n, m;
        cin >> n >> m;
        if (n % m == 0)
            ans[T] = 1;
    }

    for (int i = 0; i < t; i++) {
        if (ans[i] == 1)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
    return 0;
}