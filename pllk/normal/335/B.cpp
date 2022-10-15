#include <iostream>

using namespace std;

string s;
int n;
int t[256];

int d[3000][3000];
int p[3000][3000];
int v[3000][3000];

int laske(int a, int b) {
    if (a > b) return 0;
    if (a == b) return 1;
    if (v[a][b]) return d[a][b];
    int t = 0;
    if (s[a] == s[b]) {
        p[a][b] = 1;
        t = laske(a+1, b-1)+2;
    }
    if (laske(a+1, b) > t) {
        p[a][b] = 2;
        t = laske(a+1, b);
    }
    if (laske(a, b-1) > t) {
        p[a][b] = 3;
        t = laske(a, b-1);
    }
    d[a][b] = t;
    v[a][b] = 1;
    return t;
}

void haku(int a, int b, int c) {
    if (a > b) return;
    if (a == b) {
        if (c < 100) cout << s[a];
        return;
    }
    if (p[a][b] == 1) {
        if (c < 100) cout << s[a];
        haku(a+1, b-1, c+2);
        if (c < 100) cout << s[b];
    }
    if (p[a][b] == 2) haku(a+1, b, c);
    if (p[a][b] == 3) haku(a, b-1, c);
}

int main() {
    cin >> s;
    n = s.length();
    for (int i = 0; i < n; i++) {
        t[s[i]]++;
        if (t[s[i]] == 100) {
            for (int j = 0; j < 100; j++) cout << s[i];
            cout << endl;
            return 0;
        }
    }
    laske(0, n-1);
    haku(0, n-1, 0);
    cout << endl;
}