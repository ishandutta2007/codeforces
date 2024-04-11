#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v = {2*3,2*5,2*7,2*11,3*5,3*7,3*11,5*7,5*11,7*11};
        bool ok = false;
        for (auto a : v) {
            for (auto b : v) {
                for (auto c : v) {
                    if (a == b || a == c || b == c) continue;
                    int x = n-a-b-c;
                    if (x < 1) continue;
                    if (x == a || x == b || x == c) continue;
                    cout << "YES\n";
                    cout << a << " " << b << " " << c << " " << x << "\n";
                    ok = true;
                    goto skip;
                }
            }
        }
        skip:
        if (!ok) cout << "NO\n";
    }
}