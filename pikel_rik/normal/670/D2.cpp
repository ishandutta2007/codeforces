#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<long long> a(n, 0), b(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    long long cost = (long long)accumulate(a.begin(), a.end(), (long long)0);

    long long lo = k / cost, hi = (k + (long long)accumulate(b.begin(), b.end(), (long long)0)) / cost, mid = lo + (hi - lo) / 2, tk;
    vector<long long> temp;

    while (lo <= hi) {
        mid = lo + (hi - lo) / 2;
        tk = k;
        temp = b;

        for (int i = 0; i < n; i++) {
            if (b[i] < a[i] * mid) {
                tk -= a[i] * mid - b[i];
                temp[i] = a[i] * mid;
            }
        }
        if (tk < 0)
            hi = mid - 1;
        else if (tk >= cost)
            lo = mid + 1;
        else if (tk == 0)
            break;
        else {
            for (int i = 0; i < n; i++) {
                if (temp[i] < a[i] * (mid+1)) {
                    tk -= a[i] * (mid + 1) - temp[i];
                    temp[i] = a[i] * (mid + 1);
                }
            }
            if (tk < 0)
                break;
            else
                lo = mid + 1;
        }
    }
    cout << mid;
    return 0;
}