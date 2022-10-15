#include <iostream>

using namespace std;

typedef long long ll;

ll laske(ll a, ll b, ll c, ll x) {
    if (a > 0 && b > 0 && c > 0) {
        ll u = min(a,min(b,c))-2;
        if (u > 0) return laske(a-u,b-u,c-u,x);
    }
    if (a == 0 && b == 0 && c == 0) return 0;
    if (x == 1) {
        if (a == 0) return laske(a,b,c,2)+1;
        else return laske(a-1,b,c,2);
    }
    if (x == 2) {
        if (b == 0) return laske(a,b,c,3)+1;
        else return laske(a,b-1,c,3);
    }
    if (x == 3) {
        if (c == 0) return laske(a,b,c,1)+1;
        else return laske(a,b,c-1,1);
    }
}

int main() {
    ll a, b, c;
    ll u = 0;
    cin >> a >> b >> c;
    ll x = max(a,max(b,c));
    if (x > 5) {
        if (a < x-2) {u += x-2-a; a += x-2-a;}
        if (b < x-2) {u += x-2-b; b += x-2-b;}
        if (c < x-2) {u += x-2-c; c += x-2-c;}
    }
    ll r1 = laske(a,b,c,1);
    ll r2 = laske(a,b,c,2);
    ll r3 = laske(a,b,c,3);
    cout << u+min(r1,min(r2,r3)) << "\n";
}