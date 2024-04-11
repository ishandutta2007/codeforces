#include <iostream>

using namespace std;

int n;
int s[200][2];
int k;
int p[200];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            k++;
            s[k][0] = b;
            s[k][1] = c;
        }
        if (a == 2) {
            for (int j = 1; j <= k; j++) p[j] = 0;
            p[b] = 1;
            while (1) {
                bool m = false;
                for (int x = 1; x <= k; x++) {
                for (int y = 1; y <= k; y++) {
                    if (!p[x]) continue;
                    if (p[y]) continue;
                    if (s[y][0] < s[x][0] && s[x][0] < s[y][1]) {
                        p[y] = 1;
                        m = true;
                    }
                    if (s[y][0] < s[x][1] && s[x][1] < s[y][1]) {
                        p[y] = 1;
                        m = true;
                    }
                }
                }
                if (!m) break;
            }
            if (p[c]) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}