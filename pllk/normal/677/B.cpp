#include <iostream>

using namespace std;

typedef long long ll;

ll n, h, k;
ll x;
ll s;

int main() {
    cin >> n >> h >> k;
    for (int i = 1; i <= n; i++) {
        ll a;
        cin >> a;
        ll u = x-(h-a);
        s += u/k;
        x -= (u/k)*k;
        if (x > h-a) {
            x -= k;
            s++;
        }
        if (x < 0) x = 0;
        x += a;
    }
    s += x/k;
    x -= (x/k)*k;
    if (x > 0) s++;
    cout << s << "\n";
}