#include <iostream>

using namespace std;

#define ll long long

ll w, m;
bool ok;

void haku(ll a, ll b, ll u, int k) {
    if (a == b) ok = true;
    if (ok || u > 1e11 || k > 15) return;
    haku(a, b, u*w, k+1);
    haku(a+u, b, u*w, k+1);
    haku(a, b+u, u*w, k+1);
}

int main() {
    cin >> w >> m;
    if (w == 2 || w == 3) {
        cout << "YES\n";
        return 0;
    }
    haku(m, 0, 1, 0);
    if (ok) cout << "YES\n";
    else cout << "NO\n";
}