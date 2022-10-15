#include <iostream>

using namespace std;

int n, t;
string a;
string b;
string c;

int main() {
    cin >> n >> t;
    cin >> a >> b;
    int u = n;
    c = a;
    for (int i = 0; i < n; i++) {
        char x = 'a';
        if (a[i] == x || b[i] == x) x = 'b';
        if (a[i] == x || b[i] == x) x = 'c';
        c[i] = x;
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i] && t != u) {
            c[i] = a[i];
            u--;
        }
    }
    int z = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i] || u == t) continue;
        if (z == 0) {c[i] = a[i]; z = 1;}
        else {c[i] = b[i]; u--; z = 0;}
    }
    if (u == t) cout << c << "\n";
    else cout << "-1\n";
}