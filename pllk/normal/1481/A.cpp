#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int px, py;
        cin >> px >> py;
        string s;
        cin >> s;
        int cu = 0, cd = 0, cr = 0, cl = 0;
        for (auto x : s) {
            if (x == 'U') cu++;
            if (x == 'D') cd++;
            if (x == 'R') cr++;
            if (x == 'L') cl++;
        }
        bool r = true;
        if (px > 0) r &= cr >= px;
        if (px < 0) r &= cl >= -px;
        if (py > 0) r &= cu >= py;
        if (py < 0) r &= cd >= -py;
        if (r) cout << "YES\n";
        else cout << "NO\n";
    }
}