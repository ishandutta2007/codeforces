#include <iostream>

using namespace std;

#define ll long long

int n;
ll k;
ll d[55];

void haku(int p, ll x, int o) {
    if (p == 0) return;
    if (d[p-1] >= x) {
        cout << o << " ";
        haku(p-1, x, o+1);
    } else {
        cout << o+1 << " " << o << " ";
        haku(p-2, x-d[p-1], o+2);
    }
}

int main() {
    cin >> n >> k;
    d[0] = 1;
    d[1] = 1;
    d[2] = 2;
    for (int i = 3; i <= n; i++) {
        d[i] = d[i-1]+d[i-2];
    }
    haku(n, k, 1);
    cout << "\n";
}