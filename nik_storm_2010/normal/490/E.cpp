#include <iostream>

using namespace std;
const int N = 2e5;

string s[N], was;
bool maybe[10];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    cin >> s[0];
    if (s[0][0] == '?') {
        s[0][0] = '1';
    }
    for (size_t i = 1; i < s[0].size(); i++) {
        if (s[0][i] == '?') {
            s[0][i] = '0';
        }
    }
    for (int j = 1; j < n; j++) {
        cin >> s[j];
        was = s[j];
        int l0 = (int)s[j - 1].size();
        int l1 = (int)s[j].size();
        if (l0 > l1) {
            cout << "NO\n";
            return 0;
        }
        if (l1 > l0) {
            if (s[j][0] == '?') {
                s[j][0] = '1';
            }
            for (int i = 1; i < l1; i++) {
                if (s[j][i] == '?') {
                    s[j][i] = '0';
                }
            }
            continue;
        }
        maybe[l0] = false;
        for (int i = l0 - 1; i >= 0; i--) {
            if (was[i] != '?') {
                if (s[j - 1][i] == was[i]) {
                    maybe[i] = maybe[i + 1];
                } else if (s[j - 1][i] < was[i]) {
                    maybe[i] = true;
                } else {
                    maybe[i] = false;
                }
                continue;
            }
            if (s[j - 1][i] == '9') {
                maybe[i] = maybe[i + 1];
            } else {
                maybe[i] = true;
            }
        }
        if (!maybe[0]) {
            cout << "NO\n";
            return 0;
        }
        bool equal = true;
        for (int i = 0; i < l0; i++) {
            if (was[i] == '?') {
                if (!equal) {
                    was[i] = '0';
                } else {
                    if (maybe[i + 1]) {
                        was[i] = s[j - 1][i];
                    } else {
                        was[i] = s[j - 1][i] + 1;
                    }
                }
            }
            s[j][i] = was[i];
            if (equal == true && s[j - 1][i] < s[j][i]) {
                equal = false;
            }
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        cout << s[i] << "\n";
    }
    return 0;
}