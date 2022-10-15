#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int l = 0, r = 0;
        for (auto c : s) {
            if (c == '>') r = 1;
            if (c == '<') l = 1;
        }
        if (l == 0 || r == 0) {
            cout << n << "\n";
            continue;
        }
        int c = 0;
        for (int i = 0; i < n; i++) {
            int p = i == 0 ? n-1 : i-1;
            if (s[i] == '-' || s[p] == '-') c++;
        }
        cout << c << "\n";
    }
}