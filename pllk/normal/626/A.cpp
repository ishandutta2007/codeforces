#include <iostream>

using namespace std;

int n;
string s;
int c;

bool ok(string z) {
    int y = 0, x = 0;
    for (int i = 0; i < z.size(); i++) {
        if (z[i] == 'U') y--;
        if (z[i] == 'D') y++;
        if (z[i] == 'L') x--;
        if (z[i] == 'R') x++;
    }
    return y == 0 && x == 0;
}

int main() {
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++) {
        for (int j = 1; i+j <= n; j++) {
            if (ok(s.substr(i,j))) c++;
        }
    }
    cout << c << "\n";
}