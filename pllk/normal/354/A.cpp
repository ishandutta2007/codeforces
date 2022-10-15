#include <iostream>

#define ll long long

using namespace std;

ll n, l, r, Ql, Qr;
ll w[200000];
ll a[200000];
ll s;
ll x = -1;

int main() {
    cin >> n >> l >> r >> Ql >> Qr;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
        a[i+1] = a[i];
        a[i+1] += w[i];
        s += w[i];
    }
    for (int i = 0; i <= n; i++) {
        ll v = a[i]*l;
        ll o = (s-a[i])*r;
        if (i < n-i) {
            int q = n-i-i-1;
            if (q > 0) o += q*Qr;
        } else if (n-i < i) {
            int q = i-(n-i)-1;
            if (q > 0) v += q*Ql;
        }
        ll t = v+o;
        if (x == -1 || t < x) x = t;
    }
    cout << x << endl;
}