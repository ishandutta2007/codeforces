#include <iostream>
#include <set>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        set<int> s;
        int n;
        cin >> n;
        for (int i = 1; i <= 2*n; i++) {
            int x;
            cin >> x;
            if (s.count(x) == 0) cout << x << " ";
            s.insert(x);
        }
        cout << "\n";
    }
}