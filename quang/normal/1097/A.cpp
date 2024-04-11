#include <bits/stdc++.h>

using namespace std;

const int N = 100010;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    for (int i = 1; i <= 5; i++) {
        string t;
        cin >> t;
        if (t[0] == s[0] || t[1] == s[1]) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}