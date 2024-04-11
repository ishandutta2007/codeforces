#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> p(n, 0);
    vector<int> ans(n+1, 0);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        ans[p[i]] = i+1;
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}