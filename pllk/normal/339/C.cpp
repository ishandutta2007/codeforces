#include <iostream>

using namespace std;

string s;
int m;
bool ok;
int q[2000];

void haku(int a, int b, int k, int v) {
    if (k == m) {
        if (ok) return;
        ok = true;
        cout << "YES\n";
        for (int i = 0; i < k; i++) cout << q[i] << " ";
        cout << endl;
        return;
    }
    for (int i = 1; i <= 10; i++) {
        if (s[i-1] == '0') continue;
        if (k%2 == 0) {
            if (a+i > b && i != v) {
                q[k] = i;
                haku(a+i, b, k+1, i);
                if (k != 0) return;
            }
        } else {
            if (b+i > a && i != v) {
                q[k] = i;
                haku(a, b+i, k+1, i);
                return;
            }
        }
    }
}

int main() {
    cin >> s >> m;
    haku(0, 0, 0, -1);
    if (!ok) cout << "NO\n";
}