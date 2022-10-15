#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string a;
        cin >> a;
        string b;
        for (auto x : a) {
            b += x;
            int k = b.size();
            if (k >= 2 && b[k-2] == 'A' && b[k-1] == 'B') {
                b.pop_back();
                b.pop_back();
            }
        }
        string c;
        for (auto x : b) {
            c += x;
            int k = c.size();
            if (k >= 2 && c[k-2] == 'B' && c[k-1] == 'B') {
                c.pop_back();
                c.pop_back();
            }
        }
        cout << c.size() << "\n";
    }
}