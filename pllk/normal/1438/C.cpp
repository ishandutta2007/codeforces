#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int x;
                cin >> x;
                if ((i+j)%2 == 0 && x%2 != 0) x++;
                if ((i+j)%2 == 1 && x%2 != 1) x++;
                cout << x << " ";
            }
            cout << "\n";
        }
    }
}