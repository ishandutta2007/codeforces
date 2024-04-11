#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int sum = 0;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i < k)
            sum += a[i];
    }

    int best_sum = sum, best_j = 0;

    for (int i = 1; i <= n - k; i++) {
        sum -= a[i-1];
        sum += a[i+k-1];
        if (sum < best_sum) {
            best_sum = sum;
            best_j = i;
        }
    }

    cout << best_j + 1;
    return 0;
}