#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        s = "0"+s;
        s = s+"0";
        for (int k = 0; k < m; k++) {
            bool z = false;
            string u = s;
            for (int i = 1; i <= n; i++) {
                if (s[i] == '0' && s[i-1] == '1' && s[i+1] == '0') {
                    u[i] = '1';
                    z = true;
                }
                if (s[i] == '0' && s[i-1] == '0' && s[i+1] == '1') {
                    u[i] = '1';
                    z = true;
                }
            }
            s = u;
            if (!z) break;
        }
        for (int i = 1; i <= n; i++) cout << s[i];
        cout << "\n";
    }
}