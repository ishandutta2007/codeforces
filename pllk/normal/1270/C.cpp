#include <iostream>

using namespace std;

typedef long long ll;

int a[101010];

void lol() {
    int n;
    cin >> n;
    ll s = 0;
    ll x = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s += a[i];
        x ^= a[i];
    }
    ll g = 0, u = 0;
    if (s == 2*x) {
        cout << 0 << "\n";
        cout << "\n";
    } else {
        g = (1LL<<50)+(s%2);
        s += g;
        x ^= g;
        u = 2*x-s;
        cout << 3 << "\n";
        cout << g << " " << u/2 << " " << u/2 << "\n";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) lol();
}