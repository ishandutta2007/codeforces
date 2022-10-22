#include <bits/stdc++.h>
using namespace std;

main() {
    int n;
    cin >> n;
    vector<array<int, 2>> b, w;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i + j) % 2 == 0) {
                b.push_back({i, j});
            } else {
                w.push_back({i, j});
            }
        }
    }
    for (int i = 0; i < n * n; ++i) {
        int c;
        cin >> c;
        if (c != 1 && !b.empty()) {
            cout << "1 " << b.back()[0] + 1 << " " << b.back()[1] + 1 << endl;
            b.pop_back();
            continue;
        }
        if (c != 2 && !w.empty()) {
            cout << "2 " << w.back()[0] + 1 << " " << w.back()[1] + 1 << endl;
            w.pop_back();
            continue;
        }
        int x, y, c1;
        if (b.empty()) {
            x = w.back()[0]; y = w.back()[1];
            w.pop_back();
            c1 = 1;
        } else {
            x = b.back()[0]; y = b.back()[1];
            b.pop_back();
            c1 = 2;
        }
        for (int j = 1; j <= 3; ++j) {
            if (j != c && j != c1) {
                cout << j << " " << x + 1 << " " << y + 1 << endl;
                break;
            }
        }
    }
    return 0;
}