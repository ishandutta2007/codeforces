#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int h, n;
int a[N], b[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> h;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int low = 0, high = n + 1;
    while (high - low > 1) {
        int mid = low + high >> 1;
        long long tot = 0;
        for (int i = 1; i <= mid; i++) {
            b[i] = a[i];
        }
        sort(b + 1, b + mid + 1);
        reverse(b + 1, b + mid + 1);
        for (int i = 1; i <= mid; i += 2) {
            tot += b[i];
        }
        if (tot <= h) low = mid;
        else high = mid;
    }
    cout << low << endl;
    return 0;
}