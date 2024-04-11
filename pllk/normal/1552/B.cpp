#include <iostream>

using namespace std;

int d[50001][6];

bool better(int a, int b) {
    if (a == b) return true;
    int c = 0;
    for (int i = 1; i <= 5; i++) c += d[a][i] < d[b][i];
    return c >= 3;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 5; j++) cin >> d[i][j];
        }
        int b = 1;
        for (int i = 1; i <= n; i++) {
            if (!better(b, i)) b = i;
        }
        bool f = false;
        for (int i = 1; i <= n; i++) {
            if (!better(b, i)) f = true;
        }
        if (f) cout << "-1\n";
        else cout << b << "\n";
    }
}