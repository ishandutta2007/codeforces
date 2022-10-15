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
        int b = 0;
        for (int i = 0; i < n; i++) {
            int x = s[i]-'0';
            int u;
            if (x+1 == b) {
                u = x;
                cout << "0";
            } else {
                u = x+1;
                cout << "1";
            }
            b = u;
        }
        cout << "\n";
    }
}