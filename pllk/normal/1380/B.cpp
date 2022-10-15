#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        int cr = 0, cs = 0, cp = 0;
        for (auto c : s) {
            if (c == 'R') cr++;
            if (c == 'S') cs++;
            if (c == 'P') cp++;
        }
        char z;
        if (cr >= cs && cr >= cp) {
            z = 'P';
        } else if (cs >= cr && cs >= cp) {
            z = 'R';
        } else {
            z = 'S';
        }
        for (int i = 0; i < n; i++) cout << z;
        cout << "\n";
    }
}