#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
string s[55];
string f;
int ay, ax;

bool ok(string z) {
    int y = ay;
    int x = ax;
    for (int i = 0; i < f.size(); i++) {
        char u = f[i]-'0';
        if (z[u] == 'a') y--;
        if (z[u] == 'b') y++;
        if (z[u] == 'c') x--;
        if (z[u] == 'd') x++;
        if (y < 0 || x < 0 || y >= n || x >= m) return false;
        if (s[y][x] == 'E') return true;
        if (s[y][x] == '#') return false;
    }
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'S') {ay = i; ax = j;}
        }
    }
    cin >> f;
    string z = "abcd";
    int c = 0;
    do {
        if (ok(z)) c++;
    } while (next_permutation(z.begin(),z.end()));
    cout << c << "\n";
}