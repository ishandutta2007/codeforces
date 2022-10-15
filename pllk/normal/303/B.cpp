#include <iostream>
#include <algorithm>

#define ll long long int

using namespace std;

ll n, m, x, y, a, b;

ll gcd(ll a, ll b) {
    if (a%b == 0) return b;
    return gcd(b, a%b);
}

int main() {
    cin >> n >> m >> x >> y >> a >> b;
    ll g = gcd(a, b);
    a /= g;
    b /= g;
    ll k = 0;
    ll j = 1;
    while (j < n) j *= 2;
    for (; j >= 1; j /= 2) {
        while (a*(k+j) <= n && b*(k+j) <= m) k += j;
    }
    ll aa = a*k;
    ll bb = b*k;

    ll xx = x-aa/2;
    ll yy = y-bb/2;
    if (xx < 0) xx = 0;
    if (yy < 0) yy = 0;
    if (xx+aa >= n) xx -= (xx+aa-n);
    if (yy+bb >= m) yy -= (yy+bb-m);
    if (xx > 0 && abs(2*xx+aa-2*x) == abs(2*xx-2+aa-2*x)) xx--;
    if (yy > 0 && abs(2*yy+bb-2*y) == abs(2*yy-2+bb-2*y)) yy--;
    cout << xx << " " << yy << " " << xx+aa << " " << yy+bb << "\n";
}