#include <iostream>
#include <set>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        set<int> s;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            s.insert(x);
        }
        int c = 0;
        for (int i = 1; i <= m; i++) {
            int x;
            cin >> x;
            if (s.count(x)) c++;
        }
        cout << c << "\n";
    }
}