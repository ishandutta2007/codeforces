#include <iostream>
#include <algorithm>

using namespace std;

int n;
int t[500];
int p;

int v[500];

void etsi(int m) {
    if (v[m]) return;
    v[m] = 1;
    if (m < p) p = m;
    for (int i = 0; i <= n; i++) {
        if (n-i > 2*n-1-m) continue;
        if (i > m) continue;
        etsi(m-i+n-i);
    }
}

int main() {
    cin >> n;
    int m = 0;
    for (int i = 0; i < 2*n-1; i++) {
        cin >> t[i];
        if (t[i] < 0) {
            m++;
            t[i] = -t[i];
        }
    }
    p = m;
    etsi(m);
    sort(&t[0], &t[2*n-2]);
    int s = 0;
    for (int i = 0; i < 2*n-1; i++) {
        if (i < p) s -= t[i];
        else s += t[i];
    }
    cout << s << endl;
}