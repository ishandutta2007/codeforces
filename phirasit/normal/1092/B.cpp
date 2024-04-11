#include <bits/stdc++.h>

using namespace std;

int main() {

    cin.sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;

    vector<int> v(n);
    for (int& val : v) cin >> val;

    sort(v.begin(), v.end());

    int ans = 0;
    for (int i = 0; i < n; i += 2) {
        ans += v[i+1] - v[i];
    }

    cout << ans << endl;

    return 0;
}