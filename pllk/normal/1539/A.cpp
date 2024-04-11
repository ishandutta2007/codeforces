#include <iostream>

using namespace std;

typedef long long ll;

ll sum(ll n) {
    return n*(n+1)/2;
}

int main() {
    int k;
    cin >> k;
    while (k--) {
        ll n, x, t;
        cin >> n >> x >> t;
        ll a = t/x;
        if (n <= a) {
            cout << sum(n-1) << "\n";
        } else {
            cout << sum(a)+a*(n-a-1) << "\n";
        }
    }
}