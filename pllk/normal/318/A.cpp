#include <iostream>

#define ll long long int

using namespace std;

ll n, k;

int main() {
    cin >> n >> k;
    if (n % 2 == 1) {
        n++;
    }
    ll p = n/2;
    if (k <= p) cout << (k*2-1) << endl;
    else cout << (k-p)*2 << endl;
}