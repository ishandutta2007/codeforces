#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int c = 0;
        for (int i = 1; i <= n; i++) {
            string s;
            cin >> s;
            if (s[m-1] == 'R') c++;
            if (i == n) for (auto x : s) if (x == 'D') c++;
        }
        cout << c << "\n";
    }
}