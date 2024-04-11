#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());
    int l = 0;
    int res = 0;
    for (int r = 0; r < n; r++) {
        while (a[r] - a[l] > 5) {
            l++;
        }
        res = max(res, r - l + 1);
    }
    cout << res << "\n";

}