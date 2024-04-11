#include <iostream>

using namespace std;

int n;
string s;

int d[333][333][333];
int ta, tb, tc;

void haku(int a, int b, int c) {
    if (a == 1 && b == 0 && c == 0) ta = 1;
    if (a == 0 && b == 1 && c == 0) tb = 1;
    if (a == 0 && b == 0 && c == 1) tc = 1;
    if (d[a][b][c]) return;
    d[a][b][c] = 1;
    if (a >= 1 && b >= 1) haku(a-1,b-1,c+1);
    if (a >= 1 && c >= 1) haku(a-1,b+1,c-1);
    if (b >= 1 && c >= 1) haku(a+1,b-1,c-1);
    if (a >= 2) haku(a-1,b,c);
    if (b >= 2) haku(a,b-1,c);
    if (c >= 2) haku(a,b,c-1);
}

int main() {
    cin >> n;
    cin >> s;
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'B') a++;
        if (s[i] == 'G') b++;
        if (s[i] == 'R') c++;
    }
    haku(a,b,c);
    if (ta) cout << "B";
    if (tb) cout << "G";
    if (tc) cout << "R";
    cout << "\n";
}