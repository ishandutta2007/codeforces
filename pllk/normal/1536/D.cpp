#include <iostream>
#include <set>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        set<int> s;
        int v;
        bool f = true;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            s.insert(x);
            if (i != 1) {
                auto it = s.find(x);
                if (v < x) {
                    it--;
                    if (*it > v) f = false;
                }
                if (v > x) {
                    it++;
                    if (*it < v) f = false;
                }
            }
            v = x;
        }
        if (f) cout << "YES\n";
        else cout << "NO\n";
    }
}