#include <bits/stdc++.h>
using namespace std;

void init(vector<int>& a) {
    for (int i = 0; i < a.size(); i++) {
        a[i] = 0;
    }
    a[0] = 1;
}

int main() {
    int m, s;
    cin >> m >> s;

    if (s == 0 and m == 1)
        cout << "0 0";
    else if (s == 0 or 9 * m < s)
        cout << "-1 -1";
    else if (s == 1) {
        for (int i = 0; i < 2; i++) {
            cout << "1";
            for (int j = 1; j < m; j++) {
                cout << "0";
            }
            cout << " ";
        }
    }
    else {
        int sum = 1;
        vector<int> a(m);
        a[0] = 1;

        while (sum < s) {
            for (int i = m-1; i >= 0; i--) {
                while (sum < s and a[i] < 9) {
                    a[i] += 1;
                    sum += 1;
                }
                if (sum == s)
                    break;
            }
        }
        for (int i = 0; i < m; i++) {
            cout << a[i];
        }
        cout << " ";

        sum = 1;
        init(a);
        while (sum < s) {
            for (int i = 0; i < m; i++) {
                while (sum < s and a[i] < 9) {
                    a[i] += 1;
                    sum += 1;
                }
                if (sum == s)
                    break;
            }
        }
        for (int i = 0; i < m; i++) {
            cout << a[i];
        }
    }
    return 0;
}