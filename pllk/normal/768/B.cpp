#include <iostream>
#include <cstdlib>
#include <deque>
#include <vector>

using namespace std;

typedef long long ll;

ll n;
ll l, r;
int c;

deque<ll> u;
vector<ll> v;


void lol() {
    u.push_back(n);
    while (u.size() > 0) {
        ll x = u.front();
        u.pop_front();
        if (x < 2) {
            v.push_back(x);
        } else {
            ll a = x/2;
            ll b = x%2;
            ll c = x/2;
            u.push_front(c);
            u.push_front(b);
            u.push_front(a);
        }
    }
    ll s = 0;
    l--; r--;
    for (ll i = l; i <= r; i++) s += v[i];
    cout << s << "\n";
    exit(0);
}

int main() {
    cin >> n >> l >> r;
    if (n <= 100) lol();
    l--; r--;
    ll z = 1;
    while (2*z <= n) z *= 2;
    ll h = z;
    z = z-1;
    for (ll i = l; i <= r; i++) {
        if (i%2 == 0) c++;
        else {
            ll u = abs(z-i);
            ll g = 1;
            ll f = h;
            while (true) {
                if (u%f == 0) break;
                f /= 2;
                g *= 2;
            }
            if (n&g) {
                c++;
            }
        }
    }
    cout << c << "\n";
}