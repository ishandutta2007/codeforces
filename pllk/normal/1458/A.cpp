#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int n, m;

ll a[202020];
ll b[202020];

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1,a+n+1);
    for (int i = 1; i <= m; i++) cin >> b[i];
    if (n == 1) {
        for (int i = 1; i <= m; i++) {
            cout << a[1]+b[i] << " ";
        }
        cout << "\n";
    } else {
        ll g = a[2]-a[1];
        for (int i = 2; i <= n-1; i++) g = gcd(g,a[i+1]-a[i]);
        for (int i = 1; i <= m; i++) {
            cout << gcd(a[1]+b[i],g) << " ";
        }
        cout << "\n";
    }
}