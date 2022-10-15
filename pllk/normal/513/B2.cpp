#include <iostream>

using namespace std;

#define ll long long

ll n, m;

void tee(ll a, ll b, ll x) {
    if (a > n) return;
    if (b < x) {
        cout << a << " ";
        tee(a+1, b, x/2);
    } else {
        tee(a+1, b-x, x/2);
        cout << a << " ";
    }
}

int main() {
    cin >> n >> m;
    tee(1, m-1, 1LL<<(n-2));
    cout << "\n";
}