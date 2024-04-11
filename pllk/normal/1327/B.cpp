#include <iostream>

using namespace std;

int n;
int r[101010];

void lol() {
    cin >> n;
    for (int i = 1; i <= n; i++) r[i] = 0;
    int c = 0;
    int h1, h2;
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        int f = 0;
        for (int j = 1; j <= k; j++) {
            int x;
            cin >> x;
            if (r[x] == 0 && f == 0) {
                r[x] = 1;
                c++;
                f = 1;
            }
        }
        if (f == 0) h1 = i;
    }
    for (int i = 1; i <= n; i++) if (r[i] == 0) h2 = i;
    if (c == n) cout << "OPTIMAL\n";
    else cout << "IMPROVE\n" << h1 << " " << h2 << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) lol();
}