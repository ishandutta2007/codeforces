#include <iostream>

using namespace std;

string s;
int c[128];
int z;
int t[50][50];

int main() {
    cin >> s;
    for (int i = 0; i < 27; i++) {
        c[s[i]]++;
        if (c[s[i]] == 2) z = s[i];
    }
    for (int i = 0; i < 26; i++) {
        if (s[i] == s[i+1]) {
            cout << "Impossible\n";
            return 0;
        }
    }
    while (s[0] != z) s = s.substr(1)+s[0];
    int k;
    for (int i = 1; i < 27; i++) {
        if (s[i] == z) k = i;
    }
    k--;
    int y = 0;
    int x = 12-((k+2)/2-1);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 26; j++) t[i][j] = ' ';
    }
    int vy = y;
    int vx = x;
    t[y][x] = s[0];
    int m = 1;
    int f = 0;
    for (int i = 0; i < k; i++) {
        if (m == 1) {
            if (x != 12) x++;
            else {y++; m = 2;}
        } else if (m == 2) {
            x--;
        }
        t[y][x] = s[++f];
    }
    f++;
    m = 1;
    y = vy; x = vx;
    while (f != 26) {
        if (m == 1) {
            if (x != 0) x--;
            else {y++; m = 2;}
        } else if (m == 2) {
            x++;
        }
        t[y][x] = s[++f];
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 26; j++) cout << (char)t[i][j];
        cout << "\n";
    }
}