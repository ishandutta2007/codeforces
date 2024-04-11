#include <iostream>

using namespace std;

typedef long long ll;

ll n, k;
ll u;

int main() {
    cin >> n >> k;
    for (ll x = 1; ; x++) {
        u += x;
        if (u-(n-x) == k) {
            cout << n-x << "\n";
            return 0;
        }
    }
}