#include <iostream>

using namespace std;

int n, k;
int u, z;
int t[101010];

int main() {
    ios_base::sync_with_stdio();
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int c;
        cin >> c;
        for (int j = 0; j < c; j++) cin >> t[j];
        int x = 1;
        bool ok = true;
        for (int j = 0; j < c; j++) {
            if (t[j] == x && ok) {
                u++;
                x++;
            } else {
                ok = false;
                if (j > 0) z++;
            }
        }
    }
    cout << n-u+z << "\n";
}