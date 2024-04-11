#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        string a, b;
        cin >> a >> b;

        if (a.back() < b.back()) {
            cout << ">" << '\n';
        } else if (a.back() > b.back()) {
            cout << "<" << '\n';
        } else {
            if (a.back() == 'L') {
                swap(a, b);
            }
            if (a.length() < b.length()) {
                cout << ">" << '\n';
            } else if (a.length() > b.length()) {
                cout << "<" << '\n';
            } else {
                cout << "=" << '\n';
            }
        }
    }
    return 0;
}