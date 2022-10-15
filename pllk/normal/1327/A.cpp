#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        if (n%2 != k%2) {
            cout << "NO\n";
        } else if (n-(k-1)*(k-1) < 2*k-1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}