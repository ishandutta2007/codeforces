#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        lint k = 0;
        int zer = 0;
        string t;
        for (auto i : s) {
            if (zer == 0 && i == '0') {
                zer = 1;
            } else {
                t.push_back(i);
            }
        }
        if (zer == 1) {
            s = t;
        } else {
            cout << "cyan\n";
            continue;
        }
        for (auto i : s) {
            k += i - '0';
        }
        if (k % 3 != 0) {
            cout << "cyan\n";
            continue;
        }
        int even = 0;
        for (auto i : s) {
            if ((i - '0') % 2 == 0) {
                even = 1;
                break;
            }
        }
        if (even == 1) {
            cout << "red\n";
        } else {
            cout << "cyan\n";
        }
    }    

}