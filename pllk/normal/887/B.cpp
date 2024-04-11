#include <iostream>

using namespace std;

int n;
int x[10][100];

bool ok(int t, int b) {
    if (t == 0) return true;
    bool o = 0;
    for (int i = 1; i <= n; i++) {
        if (b&(1<<i)) continue;
        for (int j = 1; j <= 6; j++) {
            if (x[i][j] == t%10) {
                o |= ok(t/10,b|(1<<i));
            }
        }
    }
    return o;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6; j++) cin >> x[i][j];
    }
    int c = 0;
    for (int i = 1; ; i++) {
        if (ok(i,0)) c = i;
        else break;
    }
    cout << c << "\n";
}