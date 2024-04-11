#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> count(4);
    count[0] = INT_MAX;

    for (int i = 0; i < n; i++) {
        count[a[i]] += 1;
    }

    int m = INT_MAX, pos = 0;

    for (int i = 1; i < 4; i++) {
        if (count[i] < m) {
            pos = i;
            m = count[i];
        }
    }

    if (m == 0) {
        cout << "0";
    }
    else {
        cout << m << "\n";
        vector<vector<int>> b(m, vector<int> (3, 0));

        int j = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) {
                b[j][0] = i + 1;
                j += 1;
            }
            if (j == m)
                break;
        }

        j = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 2) {
                b[j][1] = i + 1;
                j += 1;
            }
            if (j == m)
                break;
        }

        j = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 3) {
                b[j][2] = i + 1;
                j += 1;
            }
            if (j == m)
                break;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < 3; j++) {
                cout << b[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}