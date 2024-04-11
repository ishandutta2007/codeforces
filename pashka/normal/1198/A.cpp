#include <bits/stdc++.h>

#define MIN_INT -2147483648
#define MAX_INT 2147483647
#define MIN_LONG -9223372036854775808L
#define MAX_LONG 9223372036854775807L

#define long long long int

using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n, s;
    cin >> n >> s;
    int k = s * 8 / n;
    if (k > 30) {
        cout << 0;
        return 0;
    }
    k = 1 << k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> b(n);
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) {
            b[i] = b[i - 1];
        } else {
            b[i] = b[i - 1] + 1;
        }
    }
    int j = 0;
    int res = 0;
    for (int i = 0; i < n; i++) {
        while (j < n && b[j] < b[i] + k) {
            j++;
        }
        res = max(res, j - i);
    }
    cout << n - res;

    return 0;
}