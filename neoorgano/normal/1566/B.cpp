#include <bits/stdc++.h>
using namespace std;

main() {
    int tst;
    cin >> tst;
    while (tst--) {
        string s;
        cin >> s;
        vector<int> ind;
        for (int i = 0; i < (int)s.size(); ++i) {
            if (s[i] == '0') {
                ind.push_back(i);
            }
        }
        if ((int)ind.size() == 0) {
            cout << 0 << "\n";
        } else {
            bool f = true;
            for (int i = 1; i < (int)ind.size(); ++i) {
                if (ind[i - 1] + 1 != ind[i]) {
                    f = false;
                    break;
                }
            }
            if (f) {
                cout << 1 << "\n";
            } else {
                cout << 2 << "\n";
            }
        }
    }
    return 0;
}