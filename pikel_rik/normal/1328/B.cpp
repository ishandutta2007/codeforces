#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        int i;

        for (i = 1; i <= n; i++) {
            k -= i;
            if (k < 0) {
                k += i;
                break;
            }
        }

        vector<int> a(n);

        if (k == 0) {
            a[i - 1] = a[i - 2] = 1;
        }
        else {
            a[i] = 1;
            a[k-1] = 1;
        }

        for (int i = n-1; i >= 0; i--) {
            if (a[i] == 0)
                cout << "a";
            else
                cout << "b";
        }
        cout << "\n";
    }
    return 0;
}