#include <iostream>

using namespace std;

typedef long long ll;

int n;
ll a[202020];
ll d1[202020];
ll d2[202020];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        d1[i] = a[i];
        if (i-2 >= 1) d1[i] += d1[i-2];
    }
    for (int i = n; i >= 1; i--) {
        d2[i] = a[i];
        if (i+2 <= n) d2[i] += d2[i+2];
    }
    if (n%2 == 0) {
        ll u = max(d1[n-1],d1[n]);
        cout << 2*u << "\n";
    } else {
        ll u = 0;
        for (int i = 1; i <= n; i++) {
            u = max(u,d1[i]+d2[i+1]);
        }
        cout << u << "\n";
    }
}