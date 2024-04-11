#include <iostream>

using namespace std;

string s[5];

bool ok(int y, int x, int a, int b) {
    int c = 0;
    for (int i = 0; i < 3; i++) {
        if (y < 0 || x < 0 || y >= 4 || x >= 4) return 0;
        if (s[y][x] == 'o') return 0;
        if (s[y][x] != 'x') c++;
        y += a;
        x += b;
    }
    return c == 1;
}

int main() {
    int z = 0;
    for (int i = 0; i < 4; i++) cin >> s[i];
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            for (int a = -1; a <= 1; a++)
            for (int b = -1; b <= 1; b++) {
                if (a == 0 && b == 0) continue;
                if (ok(y,x,a,b)) z = 1;
            }
        }
    }
    if (z == 1) cout << "YES\n";
    else cout << "NO\n";
}