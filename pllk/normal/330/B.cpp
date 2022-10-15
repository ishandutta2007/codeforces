#include <iostream>

using namespace std;

int n, m;

int k[2000];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        k[a] = 1;
        k[b] = 1;
    }
    cout << (n-1) << endl;
    for (int i = 1; i <= n; i++) {
        if (k[i]) continue;
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            cout << i << " " << j << endl;
        }
        break;
    }
}