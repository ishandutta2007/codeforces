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
        s = "#"+s;
        for (int i = 1; i <= n; i++) {
            cout << s[i+i-1];
        }
        cout << "\n";
    }
}