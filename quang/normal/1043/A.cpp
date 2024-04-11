#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int mx = 0;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
        mx = max(mx, a[i]);
    }
    int low = mx - 1, high = 1e9;
    while (high - low > 1) {
        int mid = (1ll * high + low) >> 1;
        long long tot = 0;
        for (int i = 1; i <= n; i++) {
            tot += mid - a[i];
        }
        if (tot > sum) {
            high = mid;
        } else {
            low = mid;
        }
    }
    cout << high << endl;
    return 0;
}