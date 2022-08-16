#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        int flag1 = 0;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (i > 0 and a[i] != a[i-1])
                flag1 = 1;
        }

        if (flag1 == 0) {
            cout << 1 << "\n";
            for (int i = 0; i < n; i++) {
                cout << 1 << " ";
            }
        }
        else if (n % 2 == 0 or a[n-1] == a[0]) {
            cout << 2 << "\n";
            for (int i = 0; i < n; i++) {
                cout << 1 + i % 2 << " ";
            }
        }
        else {
            int flag = 0;

            for (int i = 1; i < n; i++) {
                if (a[i] == a[i-1]) {
                    flag = i;
                    break;
                }
            }

            if (flag == 0) {
                cout << 3 << "\n";
                for (int i = 0; i < n - 1; i++) {
                    cout << 1 + i % 2 << " ";
                }
                cout << "3";
            }
            else {
                cout << 2 << "\n";

                for (int i = 0; i < flag; i++) {
                    cout << 1 + i % 2 << " ";
                }
                for (int i = flag; i < n; i++) {
                    cout << 3 - (1 + i % 2) << " ";
                }
            }
        }
        cout << "\n";
    }
    return 0;
}